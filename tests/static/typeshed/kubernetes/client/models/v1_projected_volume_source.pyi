# Stubs for kubernetes.client.models.v1_projected_volume_source (Python 2)
#
# NOTE: This dynamically typed stub was automatically generated by stubgen.

from typing import Any, Optional

class V1ProjectedVolumeSource:
    swagger_types: Any = ...
    attribute_map: Any = ...
    discriminator: Any = ...
    default_mode: Any = ...
    sources: Any = ...
    def __init__(self, default_mode: Optional[Any] = ..., sources: Optional[Any] = ...) -> None: ...
    @property
    def default_mode(self): ...
    @default_mode.setter
    def default_mode(self, default_mode: Any) -> None: ...
    @property
    def sources(self): ...
    @sources.setter
    def sources(self, sources: Any) -> None: ...
    def to_dict(self): ...
    def to_str(self): ...
    def __eq__(self, other: Any): ...
    def __ne__(self, other: Any): ...
