# Stubs for kubernetes.client.models.v1alpha1_initializer (Python 2)
#
# NOTE: This dynamically typed stub was automatically generated by stubgen.

from typing import Any, Optional

class V1alpha1Initializer:
    swagger_types: Any = ...
    attribute_map: Any = ...
    discriminator: Any = ...
    name: Any = ...
    rules: Any = ...
    def __init__(self, name: Optional[Any] = ..., rules: Optional[Any] = ...) -> None: ...
    @property
    def name(self): ...
    @name.setter
    def name(self, name: Any) -> None: ...
    @property
    def rules(self): ...
    @rules.setter
    def rules(self, rules: Any) -> None: ...
    def to_dict(self): ...
    def to_str(self): ...
    def __eq__(self, other: Any): ...
    def __ne__(self, other: Any): ...
