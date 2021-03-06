# Stubs for kubernetes.client.models.v1_initializers (Python 2)
#
# NOTE: This dynamically typed stub was automatically generated by stubgen.

from typing import Any, Optional

class V1Initializers:
    swagger_types: Any = ...
    attribute_map: Any = ...
    discriminator: Any = ...
    pending: Any = ...
    result: Any = ...
    def __init__(self, pending: Optional[Any] = ..., result: Optional[Any] = ...) -> None: ...
    @property
    def pending(self): ...
    @pending.setter
    def pending(self, pending: Any) -> None: ...
    @property
    def result(self): ...
    @result.setter
    def result(self, result: Any) -> None: ...
    def to_dict(self): ...
    def to_str(self): ...
    def __eq__(self, other: Any): ...
    def __ne__(self, other: Any): ...
