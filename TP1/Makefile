# The path to rtai binaries must be added to the PATH variable.
# e.g. in ~/.profile : PATH="/usr/realtime-3.4-9-rtai-686-pae/bin:$PATH"

obj-m := task_exo1.o task_exo2.o task_exo3_edf.o task_exo3_rm.o

KBUILD_EXTRA_SYMBOLS := $(shell rtai-config --prefix)/modules/Module.symvers
KDIR :=/lib/modules/$(shell uname -r)/build
EXTRA_CFLAGS := $(shell rtai-config --modules-cflags)

default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(CURDIR) modules

clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(CURDIR) clean
	rm -f *.o *.ko *~
