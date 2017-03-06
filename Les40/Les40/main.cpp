#include <QCoreApplication>
#include <QtXml/QtXml>
#include <QDebug>
#include <iostream>

using namespace std;

QDomElement makeElement(QDomDocument &domDoc,const QString &strName,const QString &strAttr = QString(),const QString &strText = QString())
{
    QDomElement domElement = domDoc.createElement(strName);
    if(!strAttr.isEmpty())
    {
        QDomAttr domAttr = domDoc.createAttribute("number");
        domAttr.setValue(strAttr);
        domElement.setAttributeNode(domAttr);
    }
    if(!strText.isEmpty())
    {
        QDomText domText = domDoc.createTextNode(strText);
        domElement.appendChild(domText);
    }
    return domElement;
}

QDomElement contact(QDomDocument &domDoc,QString &strName,QString &strPhone,QString &strEmail)
{
    static int nNumber = 1;
    QDomElement domElement = makeElement(domDoc,"contact",QString().setNum(nNumber));
    domElement.appendChild(makeElement(domDoc,"name","",strName));
    domElement.appendChild(makeElement(domDoc,"phone","",strPhone));
    domElement.appendChild(makeElement(domDoc,"email","",strEmail));

    nNumber++;

    return domElement;
}

void traverseNode(const QDomNode &node)
{
    QDomNode domNode = node.firstChild();
    while(!domNode.isNull())
    {
        if(domNode.isElement())
        {
            QDomElement domElement = domNode.toElement();
            if(!domElement.isNull())
            {
                if(domElement.tagName()=="contact")
                {
                    qDebug()<<"Attr:"<<domElement.attribute("number","");
                }
                else
                {
                    qDebug()<<"TagNaame:"<<domElement.tagName()<<"\tText:"<<domElement.text();
                }
            }
        }
        traverseNode(domNode);
        domNode = domNode.nextSibling();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    system("chcp 1251 > nul");

//    QDomDocument doc("adressbook");
//    QDomElement domElement = doc.createElement("adressbook");
//    doc.appendChild(domElement);
//    char input[256];
//    QString sinput;
//    qDebug()<<"Введіть к-ть ел.";
//    cin.getline(input,256);
//    cout<<input;
//    sinput.append(input);
//    int n = sinput.toInt();
//    while(n--)
//    {
//        system("CLS");
//        qDebug()<<"Залишилось "<<n<<" елементів.";
//        QVector<QString> vec;
//        qDebug()<<"Ввевіть ім'я:";
//        cin.getline(input,256);
//        vec<<input;
//        qDebug()<<"Введіть номер:";
//        cin.getline(input,256);
//        vec<<input;
//        qDebug()<<"Введіть ел. адресу:";
//        cin.getline(input,256);
//        vec<<input;
//        QDomElement contacti = contact(doc, vec[0], vec[1], vec[2]);
//        domElement.appendChild(contacti);
//    }
//    QFile file("adressbook.xml");
//    if(file.open(QIODevice::WriteOnly))
//    {
//        QTextStream(&file)<<doc.toString();
//        file.close();
//    }
    system("CLS");
    QDomDocument domDoc;
    QFile file("adressbook.xml");

    if(file.open(QIODevice::ReadOnly))
    {
        if(domDoc.setContent(&file))
        {
            QDomElement domElement = domDoc.documentElement();
            traverseNode(domElement);
        }
        file.close();
    }

    return 0;
}
