// Testing external port

// TODO
//
#include "pch.h"

#include "asio.h"
#include "external_port.h"

namespace wtools {  // to become friendly for wtools classes
class TestProcessor2 : public wtools::BaseServiceProcessor {
public:
    TestProcessor2() { s_counter++; }
    virtual ~TestProcessor2() { s_counter--; }

    // Standard Windows API to Service hit here
    void stopService() { stopped_ = true; }
    void startService() { started_ = true; }
    void pauseService() { paused_ = true; }
    void continueService() { continued_ = true; }
    void shutdownService() { shutdowned_ = true; }
    const wchar_t* getMainLogName() const { return L"log.log"; }
    void preContextCall() { pre_context_call_ = true; }

    bool stopped_ = false;
    bool started_ = false;
    bool paused_ = false;
    bool shutdowned_ = false;
    bool continued_ = false;
    bool pre_context_call_ = false;
    static int s_counter;
};  // namespace wtoolsclassTestProcessor:publiccma::srv::BaseServiceProcessor
int TestProcessor2::s_counter = 0;
}  // namespace wtools

namespace cma::world {  // to become friendly for wtools classes
#include <iostream>

TEST(ExternalPortTest, StartStop) {
    using namespace std::chrono;
    using namespace xlog::internal;

    {
        cma::world::ReplyFunc reply =
            [](const std::string Ip) -> std::vector<uint8_t> {
            char reply_text[] = "I am test\n";
            auto len = strlen(reply_text) + 1;
            std::vector<uint8_t> v;
            v.resize(len);
            for (unsigned int i = 0; i < len; i++) v[i] = reply_text[i];
            return v;
        };
        wtools::TestProcessor2 tp;
        cma::world::ExternalPort test_port(&tp, 64351);  //
        auto ret = test_port.startIo(reply);             //
        EXPECT_TRUE(ret);
        EXPECT_TRUE(test_port.io_thread_.joinable());
        ret = test_port.startIo(reply);  //
        EXPECT_FALSE(ret);

        xlog::sendStringToStdio("sleeping for 1000ms\n", Colors::kDefault);
        cma::tools::sleep(1000);
        xlog::sendStringToStdio("end of sleep\n", Colors::kDefault);
        EXPECT_TRUE(test_port.io_thread_.joinable());
        test_port.shutdownIo();  //
        EXPECT_TRUE(!test_port.io_thread_.joinable());
        EXPECT_TRUE(tp.pre_context_call_);
    }
}

TEST(ExternalPortTest, Read) {
    using namespace std::chrono;
    using namespace xlog::internal;

    {
        cma::world::ExternalPort test_port(nullptr, 0);  //
        EXPECT_EQ(test_port.defaultPort(), 0);
    }

    {
        cma::world::ExternalPort test_port(nullptr);  //
        EXPECT_EQ(test_port.defaultPort(), 0);
    }

    {
        cma::world::ExternalPort test_port(nullptr, 555);  //
        EXPECT_EQ(test_port.defaultPort(), 555);
    }
    {
        char reply_text[] = "I am test\n";
        int port = 64351;
        cma::world::ReplyFunc reply =
            [reply_text](const std::string Ip) -> std::vector<uint8_t> {
            auto len = strlen(reply_text) + 1;
            std::vector<uint8_t> v;
            v.resize(len);
            for (unsigned int i = 0; i < len; i++) {
                v[i] = reply_text[i];
            }
            return v;
        };
        cma::world::ExternalPort test_port(nullptr, port);  //
        auto ret = test_port.startIo(reply);                //
        EXPECT_TRUE(ret);
        ret = test_port.startIo(reply);  //
        EXPECT_FALSE(ret);

        xlog::sendStringToStdio("sleeping for 1000ms\n", Colors::kDefault);
        cma::tools::sleep(1000);
        xlog::sendStringToStdio("end of sleep\n", Colors::kDefault);

        using namespace asio;

        io_context ios;

        ip::tcp::endpoint endpoint(ip::make_address("127.0.0.1"), port);

        asio::ip::tcp::socket socket(ios);

        socket.connect(endpoint);

        error_code error;
        char text[256];
        auto count = socket.read_some(asio::buffer(text), error);
        EXPECT_EQ(count, strlen(reply_text) + 1);
        EXPECT_EQ(0, strcmp(text, reply_text));
        socket.close();

        test_port.shutdownIo();  //
    }
}

}  // namespace cma::world
