#include <bits/stdc++.h>
using namespace std;
class book
{
public:
    unsigned long long int book_id;
    unsigned long long int book_score;
};
class library
{
public:
    unsigned long long int sign_up_time;
    unsigned long long int shiped_books_day;
    unsigned long long int no_books;
    unsigned long long int total_cost;
    unsigned long long int id;
    vector<book>books;
};
bool predicte(library a,library b);
bool predicte2(book a,book b);
int main()
{
    freopen("b_read_on.txt","r",stdin);
    unsigned long long int B,L,D;//B books //L libraries  //D Max days
    cin>>B>>L>>D;
    vector<library> Libraries(L);
    vector<unsigned long long int>S(B); //Score of each book
    for(long long int i=0;i<B;i++)
        cin>>S[i];

    for(long long int j=0;j<L;j++)
    {
        cin>>Libraries[j].no_books>>Libraries[j].sign_up_time>>Libraries[j].shiped_books_day;
        Libraries[j].id=j;
        for(long long int i=0;i<Libraries[j].no_books;i++)
        {
            unsigned long long int temp;
            cin>>temp;
            book b;
            b.book_id=temp;
            b.book_score=S[temp];
            Libraries[j].books.push_back(b);
        }
        unsigned long long int total_cost=0;
        for(long long int i=0;i<Libraries[j].no_books;i++)
            total_cost+=Libraries[j].books[i].book_score;
        Libraries[j].total_cost=total_cost;
    }

    sort(Libraries.begin(), Libraries.end(), predicte);

    for(long long int i=0;i<L;i++)
        sort(Libraries[i].books.begin(), Libraries[i].books.end(), predicte2);


    freopen("a_answer.txt","w",stdout);
    cout<<L<<endl;
    for(long long int i=0;i<L;i++)
    {
        cout<<Libraries[i].id<<" "<<Libraries[i].no_books<<endl;
        for(book book_ : Libraries[i].books)
            cout<<book_.book_id<<" ";
        cout<<endl;
    }

    return 0;
}

bool predicte(library a,library b)
{
    return   b.total_cost*b.shiped_books_day/b.sign_up_time  <a.total_cost*a.shiped_books_day/a.sign_up_time;
}
bool predicte2(book a,book b)
{
    return b.book_score<a.book_score;
}