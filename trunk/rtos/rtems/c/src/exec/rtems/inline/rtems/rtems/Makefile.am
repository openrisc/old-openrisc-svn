##
##  $Id: Makefile.am,v 1.2 2001-09-27 11:59:18 chris Exp $
##

AUTOMAKE_OPTIONS = foreign 1.4

if INLINE
I_FILES = asr.inl attr.inl dpmem.inl event.inl eventset.inl message.inl \
    modes.inl options.inl part.inl ratemon.inl region.inl sem.inl status.inl \
    support.inl tasks.inl timer.inl

noinst_HEADERS = $(I_FILES)

PREINSTALL_FILES += $(PROJECT_INCLUDE)/rtems/rtems \
    $(noinst_HEADERS:%=$(PROJECT_INCLUDE)/rtems/rtems/%)

$(PROJECT_INCLUDE)/rtems/rtems:
	@$(mkinstalldirs) $@
$(PROJECT_INCLUDE)/rtems/rtems/%.inl: %.inl
	$(INSTALL_DATA) $< $@
endif

all-local: $(PREINSTALL_FILES)

include $(top_srcdir)/../../../automake/local.am
