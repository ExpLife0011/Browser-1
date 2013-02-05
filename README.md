Browser
=======

<pre>
Now not only curl has a cool ascii-art

█▐ ▀▄                   ▅▂ |▄▄  __
█▐ ▄▄▄▄ |█▀▄  ▄▄ |▄   ▌▐_   ▌▄  █ ▚
█▐▓░ |▐  █   ▐▓░▌ ▚|▓▞ _ ▚ ▒▌▄  █
█▐▄▄▄▄▐  ▀ ░  ▀▀         ▔      ▀

?no utf-8 support?
</pre>

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

About
-----

Inspired by the python library **mechanize.Browser** <br>
A Simple to use yet efficient headers only library (wrapped over **libcurl** / **curl** wrapper) to emulate a browser in C++.
It helps and simplify web interaction. <br>
All the regex are written by hand reducing the dependencies to one library: libcurl; which is pretty small. <br>
Keep in mind that this is really **alpha**. <br>

Why
---

I made this library to make it easier to translate my python script that use mechanize.Browser into C++. Without this library the process to do what I normally do in python is a huge pain. <br>
I might soon write the whole the cheat sheet of the equivalence of the python mechanize.Browser into the C++ Browser. <br>
You can take a look at this example of the python library called mechanize.Browser() which inspired me http://stockrt.github.com/p/emulating-a-browser-in-python-with-mechanize/ , imagine doing a simple thing like that in C++ and that's what the library does. <br>

Missing
-------

* nice Error handling (to not make the browser suddenly crash in case of errors)
* proxy auth type and http auth type for this: http://user:password@www.example.com
* ssl 3.0 and tls 1.0 same as a real browser but might add dependencies
* threaded ssl openssl gnuTLS
* br.follow_link()
* br.encoding() for utf-8 and others
* curl_multi   using this for multiple handle at the same time and pipelining
* check the $(curl-config --feature) to know with which feature the cULR library was built
* change br.response into a class like in python: <br>
<pre>
>>> dir(br.response())
['__copy__', '__doc__', '__getattr__', '__init__', '__iter__', '__module__', '__repr__', '__setattr__', '_headers', '_seek_wrapper__cache', '_seek_wrapper__have_readline', '_seek_wrapper__is_
closed_state', '_seek_wrapper__pos', '_seek_wrapper__read_complete_state', 'close', 'get_data', 'geturl', 'info', 'invariant', 'next', 'read', 'readline', 'readlines', 'seek', 'set_data', 'te
ll', 'wrapped', 'xreadlines']</pre>
* Review the whole code to make it more clean and more efficient
* use StringPoolL instead of cstring for real efficiency (long string accessed many times is cpu and ram intensive)

________________________________________________________________________________

<pre>
**BROWSER**
void init();
void clean();
bool error();
std::string status();
std::string info()
forms_class forms;
forms_class::form_class form;
links_class links;
void select_form(int number_start_from_zero);
void fetch_forms(bool allow);
void fetch_links(bool allow);
void submit(int timeout);
void set_direct_form_post(bool direct,std::string url);
std::string escape(std::string the_string);
std::string unescape(std::string the_string);
void limit_speed(int limit);
void limit_time(int limit);
void set_http_tunel(bool allow);
void set_proxy_login(std::string username, std::string passwd);
void addheaders(std::string headers_to_add[2]);
void adduseragent(std::string theuseragent);
void addheaders(std::string header_to_add,std::string second_header_to_add);
void addheaders(std::map<std::string, std::string> Headers);
void addheaders(std::vector<std::string> Headers);
void open(std::string url, int usertimeout,bool save_history);
void open(std::string url, std::string post_data, int usertimeout);
void open(std::string url, int usertimeout,std::string post_data);
void open_novisit(std::string url, int usertimeout);
void set_handle_redirect(bool allow);
void set_handle_gzip(bool allow);
void set_handle_ssl(bool allow);
void set_verbose(bool allow);
void set_cookie(std::string cookies);
void set_cookiejar(std::string cookiejar);
void set_cookiejar();
void set_dns(std::string dns_server);
void set_proxy(bool allow);
void set_proxy(std::string proxy, std::string type);
void set_interface(std::string interface_name, long int port, long int max_port);
void set_http_version_1_0(bool set_it);
void write_bytes(std::string filename);
std::string getcookies();
void reload();
std::string geturl();
std::string title();
bool intitle(std::string str);
bool inresponse(std::string str);
bool inurl(std::string str);
std::string response();
void head_request(bool allow);
CURL *get_handle();
void close();
void clear_history();
void history();
void back(int timeout);
bool viewing_html();

**links**
std::string url();
std::string name();
std::string title();
std::string target();
std::string all()

**forms**
std::vector <std::string> form_raw_container;
forms_class(std::string whole_html);
forms_class();
~forms_class();
void initialize(std::string whole_html);
std::string all();
int size();
std::vector <form_class> all_forms;
form_class operator[ ]  (int ite);

    **textarea**
    std::string value();
    std::string name();

    **select**
    std::vector <option> options;
    void change_name(std::string new_name);
    std::string name();

        **option**
        bool     selected_;
        bool selected();
        std::string value();

    **input**
    std::string name();
    std::string type();
    std::string value();
    void change_name(std::string new_name);
    void change_type(std::string new_type);
    void change_value(std::string new_value);

    **form**
    std::vector < select_struct > select;
    std::vector < input_struct  > input;
    std::vector <textarea_struct> textarea;
    bool direct_post = false;
    std::map <std::string, std::string> bytes_;
    void bytes(std::string name, std::string content_type="");
    std::string url();
    std::string method();
    bool multipart();
    void clear();
    std::string *operator[ ]  (std::string name);


**regex**
bool remove_html_comment(std::string & html_response);
void remove_html_comments(std::string & html_response);
void lower_it(std::string income, std::string & outcome);
void upper_it(std::string income, std::string & outcome);
bool word_in(std::string the_string, std::string to_search);
std::string get_after_equal(std::string html_response, std::string seeking);
void replaceAll(std::string& str, const std::string& from, const std::string& to);
std::string get_between_two_closed(std::string raw_input,std::string seeking);
void get_between_two(std::string raw_input, std::string seeking, std::vector <std::string> & container);
void get_after_delimiter(std::string html_response, std::string seeking, std::vector <std::string> &form_container);
void get_from_intern(std::string raw_input, std::string word,std::string word2, std::vector <std::string> & container);

</pre>

Examples
--------

* Simply Open a page an check the content: <br>

```c++
#include "Browser.hpp"
#include <iostream>

int main()
{
    //set up a browser instance
    Browser br;
    //use gzip compression
    br.set_handle_gzip(true);
    //allow browser redirection
    br.set_handle_redirect(true);
    br.open("http://www.somepage.com");
    //you can also set the timeout this way for 10s:
    /*
    br.open("http://www.somepage.com",10);
    */
    //you can even post right away some data this way:
    /*
    br.open("http://www.somepage.com","datatopost=something");
    //or with timeout
    br.open("http://www.somepage.com","datatopost=something",10);
    //or even this way is possible
    br.open("http://www.somepage.com",10,"datatopost=something");
    */
    //check some info
    std::cout<<br.info()
             <<"\n"
             <<br.status()
             <<"\n"
             <<br.response()
             <<"\n"
             <<br.links().all();
             <<"\n"
             <<br.forms().all();
    //you can loop through the links this way:
    for(int i=0;i<br.links.size();i++)
        cout<<br.links[i]<<"\n";
    //you can loop through the forms this way:
    for(int i=0;i<br.forms.size;i++)
        cout<<br.forms[i]<<"\n";
    //...and this is just the beginning of how easy it is!
    return 0;
}
```

* Set the browser the way you want: <br>

```c++
#include "Browser.hpp"
#include <iostream>
#include <map>
#include <vector>

int main()
{
    //set up a browser instance
    Browser br;

    //you can add a user-agent this way
    br.adduseragent("Mozilla/5.0 (X11; FreeBSD x86_64; rv:17.0) Gecko/17.0 Firefox/17.0");

    //add some headers in all thoses ways

    //with a 2D array:
    std::string header[2] = {"User-agent","Mozilla/5.0 (iPhone; U; CPU iPhone OS 5_1 like Mac OS X; en-US) AppleWebKit/534.46 (KHTML, like Gecko) Version/5.1 Mobile/9B179 Safari/7534.48.3"};
    br.addheaders(header);

    //or with a map:
    map <std::string ,std::string> some_headers;
    some_headers["User-agent"]="Mozilla/5.0 (X11; FreeBSD x86_64; rv:17.0) Gecko/17.0 Firefox/17.0";
    br.addheaders(some_headers);

    //or with 2 separate strings:
    std::string first  = "User-agent";
    std::string second = "Mozilla/5.0 (X11; FreeBSD x86_64; rv:17.0) Gecko/17.0 Firefox/17.0";

    //or with a vector (must be of even size)
    std::vector headers2;
    headers2.push_back("User-agent");
    headers2.push_back("Mozilla/5.0 (X11; FreeBSD x86_64; rv:17.0) Gecko/17.0 Firefox/17.0");
    br.addheaders(headers2);

    //to see everything that is going on
    br.set_verbose(true);

    //if you give no string to this function you will see the cookie output on the screen
    br.set_cookiejar();

    //but if you give it a string it will save the cookie in the file "my_cookies" for example
    br.set_cookiejar("/home/raptor/my_cookies");

    //this function tells the browser to follow redirections
    br.set_handle_redirect(true);

    //this function is to use gzip compression
    br.set_handle_gzip(true);

    //this function is for a better handling of ssl
    br.set_handle_ssl(true);

    //you can even set the dns resolver, but curl must be compiled with support for that
    br.set_dns("192.168.0.1");

    //a nifty function that indicates which interface to use for the transfert
    br.set_interface("wlan0");

    //you can specify the port to use
    br.set_interface("wlan0",6000);

    //you can even specify a port range
    br.set_interface("wlan0",6000,10000);

    //set those to false if you don't want to parse the page and retrieve the forms and links
    br.fetch_forms(false);
    br.fetch_links(false);


    //you can set a proxy this way:
    br.set_proxy("localhost", "socks5");

    //if you don't specify the type it automatically set it to http
    br.set_proxy("192.168.0.1");

    //login to the proxy if you need to
    br.set_proxy_login("username", "passwd");

    //set an http tunnelling
    br.set_http_tunel(true);

    //you can unset the proxy:
    br.set_proxy(false);

    //you can use http 1.0 instead of the default 1.1
    br.set_http_version_1_0(true);

    //in case of congestion you can control the speed limit in kbs
    br.limit_speed(30);
    //you can even set the limit for how many time in seconds
    br.limit_time(10);
    return 0;
}
```

* Open a page in multiple ways

```c++
#include "Browser.hpp"
#include <iostream>

int main()
{
    Browser br;

    //open a page right away
    br.open("http://www.page.com");

    //open a page with timeout or 40s
    br.open("http://www.page.com",40);

    //open a page to post something
    br.open("http://www.page.com","something=somethingelse");

    //same as above but with timeout in 2 ways
    br.open("http://www.page.com","something=somethingelse",40);
    br.open("http://www.page.com",40,"something=somethingelse");

    //open a page until some status comes true
    do
    {
        br.open("http://somepage.might.bug");
    }while( !br.viewing_html() || br.status() != "200" || br.error() );

    //refresh the current page
    br.reload();

    //go back in history - last page visited
    br.back();
    //same with 40s timeout
    br.back(40);

    //view this history
    std::cout<<br.history();

    //clear it
    br.clear_history();

    //do a header only request
    br.head_request(true);
    br.open("http://somepage.net");

    //download something to some file
    br.write_bytes("/home/user/file.jpg");
    br.open("http://site.com/image.jpg");

    //when already on a page and don't want to loose forms
    //nor history nor anything else and you want to download something (like captchas)
    //use the following
    br.write_bytes("captcha.jpg");
    br.open_novisit("http://location_of_captcha_on_the_page.jpg");

    //close our browser - not necessary if there's only 1 browser
    br.close();
    return 0;
}
```

* Playing with the forms and links

```c++
#include "Browser.hpp"
#include <iostream>

int main()
{
    //create the Browser instance
    Browser br;

    //open a page with some forms
    br.open("http://bughunters.addix.net/igbtest/formtest.php");

    //print all the forms in 1 shot
    cout<<br.forms.all();

    //loop through the forms
    for(unsigned int i =0;i<br.forms.size();i++)
    {
        //show some direct info about the form
        std::cout<<br.forms[i]
                 <<"\n==========\n"
                 <<br.forms[i].url()
                 <<"\n==========\n"
                 <<br.forms[i].method()
                 <<"\n==========\n"
                 <<br.forms[i].multipart()
                 <<"\n==========\n";

        //show some more precise infos about the inside of the form
        for(unsigned int j=0;j<br.forms[i].textarea.size();j++)
        {
            std::cout<<br.forms[i].textarea[j].name()
                     <<"\n=============\n"
                     <<br.forms[i].textarea[j].value()
                     <<"\n=============\n";
        }

        for(unsigned int j=0;j<br.forms[i].input.size();j++)
        {
            std::cout<<br.forms[i].input[j].name()
                     <<"\n=============\n"
                     <<br.forms[i].input[j].value()
                     <<"\n=============\n"
                     <<br.forms[i].input[j].type()
                     <<"\n=============\n";
        }

        for(unsigned int j=0;j<br.forms[i].select.size();j++)
        {
            std::cout<<br.forms[i].select[j].name()
                     <<"\n=============\n";
            for(unsigned int k=0;k<br.forms[i].select[j].options.size())
            {
                    std::cout<<br.forms[i].select[j].options[k].value()
                             <<"\n=============\n"
                             <<br.forms[i].select[j].options[k].selected()
                             <<"\n=============\n";
            }
        }
    }

    //Now let's see how to fill up a form we found
    //first we need to select a form to work on
    //we start counting from 0
    br.select_form(0);
    //after selecting the form we can fill it the way we want
    *br.form["name"]      = "something";
    *br.form["something"] = "anotherthing";

    //if the type of the input is "file" then it will consider the string as
    //the file location
    //if you want to set it as a file yourself you can do as follow
    br.form.bytes("name_of_form_part_that_contain_bytes");

    //don't forget to fill the value of the submit button if there are many
    //when it's finish submit the form like that
    br.submit()
    //As simple as that!

    //now what if we want to create a form out of the blue and post it somewhere
    br.set_direct_form_post(true,"http://www.page_to_post_direct.net");
    *br.form["somthing_to_post"] = "something";
    br.form.bytes("else");
    *br.form["else"] = "/usr/bin/program";
    br.submit();


    //The links

    //show all the links in one shot
    std::cout<<br.links.all()

    //Loop through all the links and show of infos about each one of them
    for(unsigned int i=0;i<br.links.size();i++)
    {
        cout<<br.links[i].url()
            <<"\n=================\n"
            <<br.links[i].name()
            <<"\n=================\n"
            <<br.links[i].title()
            <<"\n=================\n"
            <<br.links[i].target()
            <<"\n=================\n"
            /*this one is the same as br.links[i].url()*/
            <<br.links[i];
    }
    return 0;
}

```

* Mini multiple images downloader example

```c++
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
```


* What does each Regex do

```c++

//transform a string into its lower case equivalent
void lower_it(std::string income, std::string & outcome);

//transform a string into its upper case equivalent
void upper_it(std::string income, std::string & outcome);

//return true if the word to_search is present in any way in a string (case insensitive)
bool word_in(std::string the_string, std::string to_search);

//replace instance of a string with another string
void replaceAll(std::string& str, const std::string& from, const std::string& to);

//Remove 1 comments -> return true
//No more comments  -> return false
bool remove_html_comment(std::string & html_response);

//uses remove_html_comment to remove all comment in the html_response
void remove_html_comments(std::string & html_response);

//RETURN "seeking *= *\"(.*)\"
std::string get_after_equal(std::string html_response, std::string seeking);

//GET  "< *seeking(.*)< */or\ *seeking" and append it to the form_container
void get_after_delimiter(std::string html_response, std::string seeking, std::vector <std::string> &form_container);

//GET "< *seeking(.*)>" and append it to a container
void get_between_two(std::string raw_input, std::string seeking, std::vector <std::string> & container);

//GET ">(.*)< *[/|\] *seeking[ |>]" and throws a string
std::string get_between_two_closed(std::string raw_input,std::string seeking);

//"(< *word2 .* word *=.*< *[/|\] *word2 *>)"
void get_from_intern(std::string raw_input, std::string word,std::string word2, std::vector <std::string> & container);

```




