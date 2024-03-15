# BeeVerse
Cyber challenge for Hack@UCF general body meeting March 8th 2024. Ping @Jack.py on Discord with the flag or with any questions, comments, and concerns.

Flag format: hack@ucf{*flag-name*}

## Background
The CEO of bWAPP never made it back from his vacation (RIP the Biggest Bee). The head of IT has been cleaning up the former CEO's computer and found an executable program that he can't make sense of. However, something feels important about it (It's labeled IMPORTANT). The IT manager has tasked you, the sole cyber intern, to find out what's so important about this “important” program. Do you have what it takes?

Note: Windows isnt going to like you running a random .exe and will label it as a Trojan but trust there is NO MALWARE. I am not that skilled! To run this executable on Windows do the following:

+ Click on and run the exe > click on defender pop-up > select "allow on device" in drop down window. 

## Guided questions
1. What is an executable and what are the differences on Windows vs. Linux systems?
2. Is there a way to see the source code of an application?
3. How can a string from the source code be beneficial to taking a certain path in an application?

Note: You only need to submit the flag but hopefully these questions can help you work your way through the challenge.

## Resources
- For Windows OS use the IMPORTANT file with the .exe extension
- For Linux OS use the IMPORTANT file without the extension
- [Ghidra](https://ghidra-sre.org/) was used to decompile the program
- The source code will be attached so you can compare it to Ghidra's translation

## Write up
### BeeVerse Engineering?
- After getting past Windows Defender screaming at you, you are presented with a simple program that runs in your terminal. It asks for you to tell it a joke that will make it laugh and gives you only three tries. Unless you know every joke in the playbook it would be nearly impossible to brute force this. So how are we supposed to get the program to think our joke is funny? Our answer, hidden within the title of this challenge, is reverse engineering. 

- So what is [reverse engineering](https://www.zenarmor.com/docs/network-security-tutorials/what-is-reverse-engineering)? Well in our case it is the process of deconstructing software so that we can view the functionality of the source code. Often people use this for malware analysis and even for hacking games. For us, because this program is very uncomplicated we can use a tool to decompile the executable and see what the program finds funny thus unlocking a part of the code we can't access.

### Tool time!
- These "tools" are called, easily enough, software reverse engineering tools. There are many out there including Ghidra, which I used, IDA Pro, Cutter, etc. These tools transform the executable binary back into assembly language and also into higher-level sudo code. This allows you to get a look into the source code of the program and what it does. Though the translation is far from perfect, these tools are great for picking out some strings that could be very important for us. Though the tools mentioned above are different they all have the same job and also integrate features like debuggers, function call trees, and register managers.

- There are also some useful reverse engineering tools that solely search programs for strings they may contain. Tools like floss and strings are commandline-based tools that when run with a binary file will dump hidden strings to your terminal. 

### Time to work...backwards?
- Fire up a reverse engineering software of your choice and import the binary file. This write-up uses Ghidra but many of the steps will be similar in any other tool you use.

- Once the binary file is processed by Ghidra you will be greeted with a daunting user Graphical User Interface (GUI). Let's break it down. In the listing box, you will see the main disassembly that Ghidra pulled from the program. This is all in assembly code and may not be as useful to us. Unless you know assembly like the back of your hand...that ain't me. There is also a console on the bottom that will display the I/O for any scripts that you may run, once again, this is a bit out of our scope here. On the sides of Ghidra's GUI, there are useful search bars for different functions that were found. However, the most important panel is the decompiler on the right. This displays the translated assembly code in C. Though it's not perfect it is way better than the assembly. 

- Easy enough Ghidra drops you in the main function and we can see this by the huge "Bee" ASCII art that is within print statements. Does this mean we could also see the string that is our answer? Keep scrolling down and you will see a string, "Joke...now laugh." that is within a strcmp. In C a strcmp will compare two strings and return 0 if they are the same. Welp, that was easy! So it looks like that is the joke and it is comparing user input to the joke. We can also see a function call below the strcmp and if we follow that function, by clicking on it, you will see the answer is obscured in octal. 

- You can also use the function graph tool Ghidra offers to display a tree-like structure that depicts the paths that the program could take. You can even see, thus confirming, that our answer in the strcmp will cause the program to branch and call another function.

### Easy Linux CLI method
- A pretty easy way to find the answer on a Linux machine without even needing to download those complex reverse engineering tools is by downloading the binary file onto your machine and running strings on it in the command line. As you can see a huge list is spit out but only some of it is human-readable English. Some of these strings you may recognize from running the program in a terminal. You can keep trying some of the lines of text in the program and eventually, you'll hit the answer: Joke...now laugh. Or, you can also just see that the flag was also found by strings.

**Congrats intern! You found what was so important behind this IMPORTANT program. This could have been bad if we deleted such wise words from our, former, CEO.**
