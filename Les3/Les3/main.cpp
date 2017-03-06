#include <QCoreApplication>
#include <QDebug>
#include <algorithm>
#include <iostream>

using namespace std;


void print(QMap<QString,QString> myPhonebook)
{
    QMap<QString,QString>::iterator it = myPhonebook.begin();
    while (it!=myPhonebook.end()) {
        cout<<it.key().toUtf8().data()<<" - "<<it.value().toUtf8().data()<<endl;
        it++;
    }
    cout<<endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString str1 = "Lo";
    QString str2 = "stris";
    str1.append(str2);
    qDebug()<<str1;
    str1.replace("stris","gic");
    qDebug()<<str1.toUpper();

    QString str("String for delimination");
    QStringList list = str.split(" ");
    cout<<endl;
    for(int i=0;i<list.size();i++)
    {
        qDebug()<<list[i];
    }
    str.clear();
    qDebug()<<str;
    str = list.join(" ");
    qDebug()<<str;


//    QVector<int> vec = {3,2,5};
//    QVector<int> mas = {1,7,4};
//    QVector<int> arr;
//    arr = vec+mas;
//    qDebug()<<arr;
//    arr<<6;
//    qDebug()<<arr;
//    sort(arr.begin(),arr.end(),qGreater<int>());//qGreater<int>() для сортування за спаданням
//    qDebug()<<arr;
//    qDebug()<<arr.contains(8);
//    arr.erase(&arr[2],&arr[4]);
//    qDebug()<<(arr);
//    qDebug()<<vec.indexOf(2);
//    foreach (auto i, arr)//equivalent for(auto i : arr)
//    {
//        qDebug()<<"Mas["<<arr.indexOf(i)<<"] = "<<i;
//    }

//    QStack<QString> list;
//    list.push("Era");
//    list.push("Corvus Corax");
//    list.push("Gathiring");
//    while (!list.empty()) {
//        qDebug()<<list.pop();
//    }

//    QMap<QString,QString> myPhonebook;
//    myPhonebook["Ihor"] = "+380631191569";
//    myPhonebook["Ivanna"] = "+380977456929";
//    myPhonebook["Ivan"] = "+380965521951";
//    myPhonebook["Lubov"] = "+380970613539";

//    for(auto i : myPhonebook)
//    {
//        qDebug()<<myPhonebook.key(i)<<" - "<<i;
//    }
//    cout<<endl;

//    myPhonebook.insert("Vassy","+380984026099");
//    print(myPhonebook);
//    QMultiMap <QString,int> mult;
//    mult.insert("Ihor",76);
//    mult.insert("Ivanna",83);
//    mult.insert("Ihor",75);
//    mult.insert("Ivanna",92);
//    mult.insert("Ihor",77);

//    QMultiMap<QString,int>::iterator it = mult.begin();
//    while(it!=mult.end())
//    {
//        qDebug()<<it.key()<<" - "<<it.value();
//        it++;
//    }

//    setlocale(LC_ALL,"ukr");
//    QSet<QString> set1;
//    QSet<QString> set2;
//    set1<<"Moon"<<"Earth"<<"Venus";
//    set2<<"Fobos"<<"Saturn"<<"Moon";
//    qDebug()<<"Множина A = "<<set1.toList();
//    qDebug()<<"Множина B = "<<set2.toList();

//    QSet<QString> setResult = set1;
//    setResult.unite(set2);
//    qDebug()<<"Об'єдняння A з B = "<<setResult.toList();
//    setResult = set1;
//    setResult.intersect(set2);
//    qDebug()<<"Перетин A з B = "<<setResult.toList();
//    setResult = set1;
//    setResult.subtract(set2);
//    qDebug()<<"Різниця A з B = "<<setResult.toList();



    return a.exec();
}
