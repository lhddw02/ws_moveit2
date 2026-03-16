from setuptools import find_packages
from setuptools import setup

setup(
    name='yolov8_obb_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('yolov8_obb_msgs', 'yolov8_obb_msgs.*')),
)
