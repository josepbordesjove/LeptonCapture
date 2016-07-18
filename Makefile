.PHONY: clean All

All:
	@echo "----------Building project:[ Lepton_SDK - Debug ]----------"
	@cd "Lepton_SDK" && $(MAKE) -f  "Lepton_SDK.mk"
clean:
	@echo "----------Cleaning project:[ Lepton_SDK - Debug ]----------"
	@cd "Lepton_SDK" && $(MAKE) -f  "Lepton_SDK.mk" clean
