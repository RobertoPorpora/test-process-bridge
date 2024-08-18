# Process Bridge Test

This is a repository of tests for the various *_process_bridge projects.  
You can use this to test if the process_bridges work on your OS / machine.  
All of these projects are imported here as submodules inside the folder `lib/`.  

## How to run the tests

The test runner is a command line script in Python.  
It compiles what needs to be compiled and then it runs the tests.  
You just need to open a terminal in the folder of this README.md and type `python test.py`.  

## Test patterns

These test patterns are tested for all languages.

- P: Parent process
- C: Child process

Every message from  C to P is meant to be sent both via stdout and stderr.  
Every save and check is performed for both stdout and stderr.  
All the possible parents programs are tested against all the possible child programs.  

### Test 1

P -> C : (spawn)  
P -> C : 'p1' (C saves as [Crx0])  
P -> C : 'p2' (C saves as [Crx1])  
P -> C : 'p3' (C saves as [Crx2])  

P <- C : 'c1 [Crx0] [Crx1] [Crx2]' (P saves as [Prx0])  
P <- C : 'c2' (P saves as [Prx1])  
P <- C : 'c3' (P saves as [Prx2])  

(C waits 1 second and then returns '12')

P waits for C to end and saves its return code as [Crc]

P checks:
- [Prx0] == "c1 p1 p2 p3"
- [Prx1] == "c2"
- [Prx2] == "c3"
- [Crc] == "12"


### Test 2

P -> C : (spawn)  
P -> C : 'p1' (C saves as [Crx0])  
P -> C : 'p2' (C saves as [Crx1])  
P -> C : 'p3' (C saves as [Crx2])  

P <- C : 'c1 [Crx0] [Crx1] [Crx2]' (P saves as [Prx0])  
P <- C : 'c2' (P saves as [Prx1])  
P <- C : 'c3' (P saves as [Prx2])  

(C waits 1 second and then returns '12')

P despawns C before it ends and saves its return code as [Crc]

P checks:
- [Prx0] == "c1 p1 p2 p3"
- [Prx1] == "c2"
- [Prx2] == "c3"
- [Crc] == "null"
