PKG_NAME = EDHOC-C
PKG_URL = https://github.com/future-proof-iot/EDHOC-C.git
PKG_VERSION = 27be50625bed86f7b2d3cbedc373e0c26f276e93
PKG_LICENSE = BSD-3-Clause

include $(RIOTBASE)/pkg/pkg.mk

CFLAGS += -Wno-newline-eof

.PHONY: edhoc-c_%

EDHOC_C_MODULES := $(filter edhoc-c_%,$(USEMODULE))

all: $(EDHOC_C_MODULES)
	$(QQ)"$(MAKE)" -C $(PKG_SOURCE_DIR)/src -f $(RIOTBASE)/Makefile.base MODULE=edhoc-c

edhoc-c_crypto_%:
	$(QQ)"$(MAKE)" -C $(PKG_SOURCE_DIR)/src/crypto -f $(RIOTBASE)/Makefile.base MODULE=$@ SRC=$*.c

edhoc-c_cbor_%:
	$(QQ)"$(MAKE)" -C $(PKG_SOURCE_DIR)/src/cbor -f $(RIOTBASE)/Makefile.base MODULE=$@ SRC=$*.c
