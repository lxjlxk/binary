PKG_NAME=tensorflow-lite
PKG_URL=https://github.com/tensorflow/tensorflow
# 2.2.2
PKG_VERSION=d745ff2a48cebf18e847e8b602a744e97e058946
PKG_LICENSE=Apache2.0

include $(RIOTBASE)/pkg/pkg.mk

TF_MODULES   = tensorflow-lite-hello_world
TF_USEMODULE = $(filter $(TF_MODULES),$(USEMODULE))

.PHONY: tensorflow-lite tensorflow-lite-%

CFLAGS += -Wno-pedantic
CFLAGS += -Wno-cast-align
CXXEXFLAGS += -Wno-maybe-uninitialized
CFLAGS += -DTF_LITE_STATIC_MEMORY
CFLAGS += -DTF_LITE_USE_GLOBAL_ROUND

all: tensorflow-lite

tensorflow-lite: $(TF_USEMODULE)
	$(QQ)"$(MAKE)" -C $(PKG_SOURCE_DIR)/tensorflow/lite/c -f $(CURDIR)/Makefile.$(PKG_NAME)-c
	$(QQ)"$(MAKE)" -C $(PKG_SOURCE_DIR)/tensorflow/lite/core/api -f $(CURDIR)/Makefile.$(PKG_NAME)-core
	$(QQ)"$(MAKE)" -C $(PKG_SOURCE_DIR)/tensorflow/lite/kernels -f $(CURDIR)/Makefile.$(PKG_NAME)-kernels
	$(QQ)"$(MAKE)" -C $(PKG_SOURCE_DIR)/tensorflow/lite/kernels/internal -f $(CURDIR)/Makefile.$(PKG_NAME)-kernels-internal
	$(QQ)"$(MAKE)" -C $(PKG_SOURCE_DIR)/tensorflow/lite/micro/kernels -f $(CURDIR)/Makefile.$(PKG_NAME)-micro-kernels
	$(QQ)"$(MAKE)" -C $(PKG_SOURCE_DIR)/tensorflow/lite/micro/memory_planner -f $(CURDIR)/Makefile.$(PKG_NAME)-memory
	$(QQ)"$(MAKE)" -C $(PKG_SOURCE_DIR)/tensorflow/lite/micro -f $(CURDIR)/Makefile.$(PKG_NAME)

tensorflow-lite-%:
	$(QQ)"$(MAKE)" -C $(PKG_SOURCE_DIR)/tensorflow/lite/micro/examples/$* -f $(CURDIR)/Makefile.$(PKG_NAME)-$*
