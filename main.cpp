/*
Now not only curl has a cool(shitty) ascii-art

█▐ ▀▄                   ▅▂  |▄▄  __
█▐ ▄▄▄▄ |█▀▄  ▄▄ |▄   ▌▐__   ▌▄  █ ▚
█▐▓░ |▐  █   ▐▓░▌ ▐|▓| _  ▍ ▒▌▄  █
█▐▄▄▄▄▐  ▀ ░  ▀▀        ▔        ▀

?no utf-8 support?(damn it!)


License (unixhub)
-----------------

    Copyright (c) 2013, Patrick Louis <patrick@unixhub.net>

    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

        1.  The author is informed of the use of his/her code. The author does not have to consent to the use; however he/she must be informed.
        2.  If the author wishes to know when his/her code is being used, it the duty of the author to provide a current email address at the top of his/her code, above or included in the copyright statement.
        3.  The author can opt out of being contacted, by not providing a form of contact in the copyright statement.
        4.  If any portion of the author’s code is used, credit must be given.
                a. For example, if the author’s code is being modified and/or redistributed in the form of a closed-source binary program, then the end user must still be made somehow aware that the author’s work has contributed to that program.
                b. If the code is being modified and/or redistributed in the form of code to be compiled, then the author’s name in the copyright statement is sufficient.
        5.  The following copyright statement must be included at the beginning of the code, regardless of binary form or source code form.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
    ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    Except as contained in this notice, the name of a copyright holder shall not
    be used in advertising or otherwise to promote the sale, use or other dealings
    in this Software without prior written authorization of the copyright holder.
*/

//let's put some examples here

#include "Browser.hpp"
#include <iostream>
#include <sstream>

int main()
{
    Browser br;
    //download 10 images;
    std::ostringstream o;
    int number = 10;
    for(int i=1;i<number;i++)
    {
        o.str("");
        o.clear()
        o<<i;
        do
        {
            br.write_bytes("/home/user/download/image"+o+".jpg");
            //let's put a big timeout because we may have big images
            br.open("http://www.imagessite.com/image"+o+"something.jpg",200);
        }while(br.error());
        std::cout<<"\nImage number "+o+" has been saved";
    }

    return 0;
}
