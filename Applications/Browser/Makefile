OBJS = \
    main.o

PROGRAM = Browser

LIB_DEPS = GUI HTML Draw IPC Protocol Core

main.cpp: ../../Libraries/LibHTML/CSS/PropertyID.h
../../Libraries/LibHTML/CSS/PropertyID.h:
	@$(MAKE) -C ../../Libraries/LibHTML

main.cpp: ../../Servers/ProtocolServer/ProtocolClientEndpoint.h
../../Servers/ProtocolServer/ProtocolClientEndpoint.h:
	@$(MAKE) -C $(dir $(@))

include ../../Makefile.common
