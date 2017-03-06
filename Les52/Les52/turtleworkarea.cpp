#include "TurtleWorkArea.h"

TurtleWorkArea::TurtleWorkArea(QWidget *parent) : QWidget(parent)
{
    m_pTurtle = new Turtle;
    m_pTurtle->setFixedSize(400,400);
    m_ptxt = new QTextEdit;

    QComboBox *pcbo = new QComboBox;
    QStringList lst;

    lst<<"Haus vom Nicolaus"<<"Curly"<<"Circle"<<"Star"<<"Fantasy";
    pcbo->addItems(lst);
    connect(pcbo,SIGNAL(activated(int)),SLOT(slotApplyCode(int)));
    slotApplyCode(0);

    QScriptValue scriptTurtle = m_scriptEngine.newQObject(m_pTurtle);
    m_scriptEngine.globalObject().setProperty("turtle",scriptTurtle);

    QPushButton *pcmd = new QPushButton("&Evaluate");
    connect(pcmd,SIGNAL(clicked()),SLOT(slotEvaluate()));

    QGridLayout *pgrdLayout = new QGridLayout;
    pgrdLayout->addWidget(pcbo,0,0);
    pgrdLayout->addWidget(m_ptxt,1,0);
    pgrdLayout->addWidget(m_pTurtle,0,1,2,1);
    pgrdLayout->addWidget(pcmd,2,0,1,2);
    setLayout(pgrdLayout);
}
void TurtleWorkArea::slotApplyCode(int n)
{
    QString strCode;
    switch (n) {
    case 0:
        strCode = "var k =100;\n"
                  "turtle.reset();\n"
                  "turtle.right(90);\n"
                  "turtle.back(-k);\n"
                  "turtle.left(90);\n"
                  "turtle.forvard(k);\n"
                  "turtle.left(30);"
                  "turtle.forvard(k);"
                  "turtle.left(120);\n"
                  "turtle.forvard(k);\n"
                  "turtle.left(30);\n"
                  "turtle.forvard(k);\n"
                  "turtle.left(135);\n"
                  "turtle.forvard(Math.sqrt(2)*k);\n"
                  "turtle.left(135);\n"
                  "turtle.forvard(k);\n"
                  "turtle.left(135);\n"
                  "turtle.forvard(Math.sqrt(2)*k);\n";
        break;
    case 1:
        strCode = "turtle.reset();\n"
                  "for(i=0;i<17;++i){\n"
                  "   for(j=0;j<100;++j){\n"
                  "       turtle.forvard(15);\n"
                  "       turtle.left(100-j);\n"
                  "   }\n"
                  "   turtle.right(180);\n"
                  "}";
        break;
    case 2:
        strCode = "turtle.reset();\n"
                  "for(var i=0;i<360;++i){\n"
                  "   turtle.forvard(150);\n"
                  "   turtle.left(99);\n"
                  "}\n";
        break;
    case 3:
        strCode = "turtle.reset();\n"
                  "turtle.left(18);\n"
                  "turtle.forvard(100);\n"
                  "for(j = 0;j<20;j++)\n"
                  "{"
                  "   turtle.left(-18);\n"
                  "   turtle.forvard(5);\n"
                  "   turtle.left(18);\n"
                  "   for(i = 0;i<5;i++)\n"
                  "   {\n"
                  "      turtle.left(144);\n"
                  "      turtle.forvard(100+j);\n"
                  "      turtle.right(72);\n"
                  "      turtle.forvard(100+j);\n"
                  "   }\n}";
        break;
    default:
        strCode = "turtle.reset();\n"
                  "for(i=0;i<200;++i){\n"
                  "   turtle.forvard(i*2);\n"
                  "   turtle.left(91);\n"
                  "}";
        break;
    }
    m_ptxt->setPlainText(strCode);
}
void TurtleWorkArea::slotEvaluate()
{
    QScriptValue result = m_scriptEngine.evaluate(m_ptxt->toPlainText());
    if(result.isError())
    {
        QMessageBox::critical(0,"Evaluating Error",result.toString(),QMessageBox::Yes);
    }
}
