# Stubs for kubernetes.client.models.v1_endpoint_subset (Python 2)
#
# NOTE: This dynamically typed stub was automatically generated by stubgen.

from typing import Any, Optional

class V1EndpointSubset:
    swagger_types: Any = ...
    attribute_map: Any = ...
    discriminator: Any = ...
    addresses: Any = ...
    not_ready_addresses: Any = ...
    ports: Any = ...
    def __init__(self, addresses: Optional[Any] = ..., not_ready_addresses: Optional[Any] = ..., ports: Optional[Any] = ...) -> None: ...
    @property
    def addresses(self): ...
    @addresses.setter
    def addresses(self, addresses: Any) -> None: ...
    @property
    def not_ready_addresses(self): ...
    @not_ready_addresses.setter
    def not_ready_addresses(self, not_ready_addresses: Any) -> None: ...
    @property
    def ports(self): ...
    @ports.setter
    def ports(self, ports: Any) -> None: ...
    def to_dict(self): ...
    def to_str(self): ...
    def __eq__(self, other: Any): ...
    def __ne__(self, other: Any): ...
