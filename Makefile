.PHONY: clean All

All:
	@echo "----------Building project:[ LeptonCapture - Debug ]----------"
	@cd "LeptonCapture" && $(MAKE) -f  "LeptonCapture.mk"
clean:
	@echo "----------Cleaning project:[ LeptonCapture - Debug ]----------"
	@cd "LeptonCapture" && $(MAKE) -f  "LeptonCapture.mk" clean
