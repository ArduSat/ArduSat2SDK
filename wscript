#!/usr/bin/env python
# encoding: utf-8
from waflib.Build import BuildContext

top = '.'
out = 'build'

def configure(ctx):
    pass

def package(ctx):
    # TODO map driver source in src/ and include/ to arduino libs
    ctx(rule='mkdir ArduSat2SDK || echo ''; cp -r ../arduino/* ArduSat2SDK; cd ArduSat2SDK; zip -r ArduSat2SDK.zip *', always=True)

class Package(BuildContext):
    cmd = 'package'
    fun = 'package'
