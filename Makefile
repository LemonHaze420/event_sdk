.ONESHELL: 

clean:
	cd event_script
	rm -f event.elf event.EV1 event.EV2 event.EV3
	cd ../event_simple_example	
	rm -f event.elf event.EV1 event.EV2 event.EV3        
all:
	cd event_script
	make TYPE=EV1
	make TYPE=EV2
	make TYPE=EV3
	cd ../event_simple_example
	make TYPE=EV1
	make TYPE=EV2
	make TYPE=EV3
        