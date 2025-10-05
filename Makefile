MAKEFLAGS += -s

FIRMWARE_REPO := ~/Repositories/qmk_firmware
KEYBOARD := keebio/iris/rev7
KEYMAP := Cathyprime

FLASH ?= yes
DEBUG ?= no

define qmk_cmd
$(MAKE) -C $(FIRMWARE_REPO) $(KEYBOARD):$(1)$(if $(filter yes,$(FLASH)),:flash) CONSOLE_ENABLE=$(DEBUG)
endef

define run
	@echo "keymap :: $(KEYMAP)"
	@echo "flash  :: $(FLASH)"
	@echo "debug  :: $(DEBUG)"
	$(call qmk_cmd,$(KEYMAP)) && $(call qmk_cmd,$(KEYMAP))
endef

all:
	$(call run)

debug:
	$(eval DEBUG := yes)
	$(call run)

%:
	$(eval KEYMAP := $*)
	$(call run)
