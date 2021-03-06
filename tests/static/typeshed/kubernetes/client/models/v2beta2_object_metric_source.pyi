# Stubs for kubernetes.client.models.v2beta2_object_metric_source (Python 2)
#
# NOTE: This dynamically typed stub was automatically generated by stubgen.

from typing import Any, Optional

class V2beta2ObjectMetricSource:
    swagger_types: Any = ...
    attribute_map: Any = ...
    discriminator: Any = ...
    described_object: Any = ...
    metric: Any = ...
    target: Any = ...
    def __init__(self, described_object: Optional[Any] = ..., metric: Optional[Any] = ..., target: Optional[Any] = ...) -> None: ...
    @property
    def described_object(self): ...
    @described_object.setter
    def described_object(self, described_object: Any) -> None: ...
    @property
    def metric(self): ...
    @metric.setter
    def metric(self, metric: Any) -> None: ...
    @property
    def target(self): ...
    @target.setter
    def target(self, target: Any) -> None: ...
    def to_dict(self): ...
    def to_str(self): ...
    def __eq__(self, other: Any): ...
    def __ne__(self, other: Any): ...
