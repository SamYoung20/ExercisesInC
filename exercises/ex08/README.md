Reflection on Debugging!
I spent about 2 hours downloading glib and compiling the above program.
after a seemingly smooth download of glib I misinterpretted the missing .h files
as an improper install of glib so I spent alot of time trying to reinstall using
a variety of different ways. Upon recognizing that glib was properly installed
from the beginning I went back to think about the root cause of the missing
.h files. This was because they were not linked properly.

The error messages I got said that the directories could not be found. So I went
to those directories and found that some of them existed and some of them actually
did not. I had to located the missing directory (it was hidden in a lower level
folder) that the IBM tutorial did not include. I needed
 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include the tutorial used
 -I/usr/lib/glib-2.0/include Once all of the directories were
properly located the code compiled cleanly.
