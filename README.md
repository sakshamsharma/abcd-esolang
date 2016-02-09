# abcd-esolang
A modified esolang tailor-made for Chaos '16 - Techkriti IIT Kanpur.

*Note*: This language is NOT the "ABCD" esolang you'd find if you google for it. I'd suggest you focus on the contest.
Googling won't help &#9786

# So how to begin
There are 2 major ways to use this language.

## Online:
Taking note of the issues in the preceeding years, this year we ensured that the interpreter for the language is
available online. We've made an interpreter in JavaScript (Open Source), and have deployed it online as well.
You can access it at [http://chaos.techkriti.org/interpreter.html]. Feel free to write and test your code here.
We've also ensured that it does not crash your browser if you mess up. So the number of instructions you can run is capped
at 20000.

## Offline:
If you use git, you know what to do. Clone the repo, download the source code.
Compile the C++ code. Use it as you would.
Otherwise, go here:
[https://github.com/sakshamsharma/abcd-esolang/archive/master.zip].
This should download this folder as a .zip file. Extract it

### Linux
`cd abcd-esolang` (or whatever the name of the file is)
`g++ abcd.cpp -o abcd`

You should now write your programs in files and run them as follows:

Assuming your program is in the same folder as the one above.
```
./abcd <program.ab>
```

You can also add abcd to your path using the following command:

```
echo "PATH=/home/<youruser>/abcd-esolang/:$PATH" > ~/.bashrc
```

Of course, you need to replace <youruser> with your username, and adjust the path appropriately.

### Windows
This is slightly more tough. You should install MinGW and get an installation of g++ on your PC. Not recommended.

# NOTE
We've tried to keep both the C++ and the JavaScript interpreters to behave the same, it may happen that they may not.
The judging will be done on the C++ interpreter.

# DOCUMENTATION
It is available here [http://chaos.techkriti.org/documentation.html]
