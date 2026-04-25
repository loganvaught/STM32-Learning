# STM32-Learning
Practice / tutorial projects and notes for learning about STM32 and embedded stuff!


Topics:

**Custom Libraries**
First time implementing a custom library: xv_functions under Core/Inc
Takeaways: 
1. Learned about the importance of function and overwrite order in main.c, and that nested functions (like overwriting _write()) do not work and must be defined globally.
2. For the serial monitor I used (PuTTY), using \r and \n in a specific order did not display print statements, and I found that "%s\r\n" worked best
