import pytest


#TODO more tests
@pytest.mark.parametrize("params,result", [({
    "access_key_id": "user",
    "secret_access_key": "d1ng",
    "regions": ['region-eu'],
}, [
    '--access-key-id', 'user', '--secret-access-key', 'd1ng', '--regions', 'region-eu',
    '--hostname', 'host'
])])
def test_aws(check_manager, params, result):
    agent = check_manager.get_special_agent("agent_aws")
    arguments = agent.argument_func(params, "host", "address")
    assert arguments == result
