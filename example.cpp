/*
Copyright (c) 2013, Patrick Louis <patrick at unixhub.net>
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


///Example showing an easy session on the amazing UH website
///This checks if there's new post you haven't read yet.
#include <iostream>
#include "Browser.hpp"
#include <fstream>
using namespace std;


int main()
{
    //create the Browser instance
    Browser br;
    //set some browser options
    br.adduseragent("Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.0.1) Gecko/2008071615 Fedora/3.0.1-1.fc9 Firefox/3.0.1");
    br.set_handle_redirect(true);
    br.set_handle_gzip(true);
    br.set_handle_ssl(true);
    br.fetch_forms(false);
    br.fetch_links(true);
    //open the page with the new links
    br.open("http://forums.unixhub.net/member.php","username=user&password=password&remember=yes&submit=Login&action=do_login");
    br.open("http://forums.unixhub.net/search.php?action=getdaily");
    //check if there's a new post
    bool new_post = false;
    for(int i=0;i<br.links.size();i++)
    {
        if(br.links[i].clas() == " subject_new")
        {
            if(new_post==false)
            {
                cout<<"New Post:\n";
                new_post = true;
            }
            cout<<"[*]  \""<<br.links[i].name()<<"\" ==> "<< br.get_root()<<br.links[i]<<"\n";
        }
    }
    //show the end of the program
    cout<<"\n====================================================\n";
    return 0;
}
