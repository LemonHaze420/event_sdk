.ONESHELL: 

clean:
	cd event_sample_bicycle_creator
	rm -f *.elf *.EV1 *.EV2 *.EV3
	cd ../event_sample_controller
	rm -f *.elf *.EV1 *.EV2 *.EV3 
	cd ../event_sample_cutscene_viewer	
	rm -f *.elf *.EV1 *.EV2 *.EV3         
all:
	cd event_sample_bicycle_creator
	make TYPE=EV1
	make TYPE=EV2
	make TYPE=EV3
	cd ../event_sample_controller
	make TYPE=EV1
	make TYPE=EV2
	make TYPE=EV3
	cd ../event_sample_cutscene_viewer
	make TYPE=EV1
	make TYPE=EV2
	make TYPE=EV3        