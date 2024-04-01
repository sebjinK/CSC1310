#include <iostream> 

using namespace std;

class cum
{
        string title;
        string author;
        string isbn;
        string pages[10];
        string getpage(int pagenum);
        {
            return pages [pagenum];
        }
    
};

class rectangle
{
    private:
        int length, width;
    public:
        rectangle(int leng, int wid) //regular contructordthe reason it doesn't have a return type is that it acts like a void type and will fill in data to those attributes
        {
            length = leng;
            width = wid;            
        }
        /*
        rectangle() = default constructutor in the case we don't have data to start out with
        {
            length = 1;
            width = 0;            
        */
        void setLen(int leng) //connect leng to length down in int main()
        {
            if (leng <= 0)
                length = 1;
        }
        string getLen
        {   
            return length;
        }
        void setWidth(int wid)
};
int main()
{
    cum yummers;

    rectangle rect;
    rect.length = 10;
    rect.width = -2;


    yummers.title = "Cum ";
    x = 25;
    y = 45;

    for (int i = 1; i < y; i++)
    {
        for (int j = 0; j < i; i++)
        {
            cout <<
            //cout << title;
        }
    }

    return 0;
}