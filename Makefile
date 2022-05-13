.ONESHELL: 

clean:
	cd event_script
	rm -f *.elf *.EV1 *.EV2 *.EV3
	cd ../event_controller_sample
	rm -f *.elf *.EV1 *.EV2 *.EV3 
	cd ../event_cutscene_viewer	
	rm -f *.elf *.EV1 *.EV2 *.EV3         
all:
	cd event_script
	make TYPE=EV1
	make TYPE=EV2
	make TYPE=EV3
	cd ../event_controller_sample
	make TYPE=EV1
	make TYPE=EV2
	make TYPE=EV3
	cd ../event_cutscene_viewer
	make TYPE=EV1
	make TYPE=EV2
	make TYPE=EV3        