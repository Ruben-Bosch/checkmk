CHECK_MYSQL_HEALTH := check_mysql_health
CHECK_MYSQL_HEALTH_VERS := 2.2.2
CHECK_MYSQL_HEALTH_DIR := $(CHECK_MYSQL_HEALTH)-$(CHECK_MYSQL_HEALTH_VERS)

CHECK_MYSQL_HEALTH_BUILD := $(BUILD_HELPER_DIR)/$(CHECK_MYSQL_HEALTH_DIR)-build
CHECK_MYSQL_HEALTH_INSTALL := $(BUILD_HELPER_DIR)/$(CHECK_MYSQL_HEALTH_DIR)-install
CHECK_MYSQL_HEALTH_UNPACK := $(BUILD_HELPER_DIR)/$(CHECK_MYSQL_HEALTH_DIR)-unpack
CHECK_MYSQL_HEALTH_SKEL := $(BUILD_HELPER_DIR)/$(CHECK_MYSQL_HEALTH_DIR)-skel

.PHONY: $(CHECK_MYSQL_HEALTH) $(CHECK_MYSQL_HEALTH)-install $(CHECK_MYSQL_HEALTH)-skel $(CHECK_MYSQL_HEALTH)-clean

$(CHECK_MYSQL_HEALTH): $(CHECK_MYSQL_HEALTH_BUILD)

$(CHECK_MYSQL_HEALTH)-install: $(CHECK_MYSQL_HEALTH_INSTALL)

$(CHECK_MYSQL_HEALTH)-skel: $(CHECK_MYSQL_HEALTH_SKEL)

# Configure options for Nagios. Since we want to compile
# as non-root, we use our own user and group for compiling.
# All files will be packaged as user 'root' later anyway.
CHECK_MYSQL_HEALTH_CONFIGUREOPTS = ""

$(CHECK_MYSQL_HEALTH_BUILD): $(CHECK_MYSQL_HEALTH_UNPACK)
	for i in configure.ac aclocal.m4 configure Makefile.am Makefile.in ; do \
	  test -f $(CHECK_MYSQL_HEALTH_DIR)/$$i && touch $(CHECK_MYSQL_HEALTH_DIR)/$$i ; \
	done
	cd $(CHECK_MYSQL_HEALTH_DIR) ; ./configure $(CHECK_MYSQL_HEALTH_CONFIGUREOPTS)
	$(MAKE) -C $(CHECK_MYSQL_HEALTH_DIR)
	$(TOUCH) $@

$(CHECK_MYSQL_HEALTH_INSTALL): $(CHECK_MYSQL_HEALTH_BUILD)
	[ -d $(DESTDIR)$(OMD_ROOT)/lib/nagios/plugins ] || mkdir -p $(DESTDIR)$(OMD_ROOT)/lib/nagios/plugins
	install -m 755 $(CHECK_MYSQL_HEALTH_DIR)/plugins-scripts/check_mysql_health $(DESTDIR)$(OMD_ROOT)/lib/nagios/plugins
	$(TOUCH) $@

$(CHECK_MYSQL_HEALTH_SKEL):

$(CHECK_MYSQL_HEALTH)-clean:
	rm -rf $(CHECK_MYSQL_HEALTH_DIR) $(BUILD_HELPER_DIR)/$(CHECK_MYSQL_HEALTH_DIR)*