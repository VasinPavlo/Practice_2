#include "neuron.h"

Neuron::Neuron(QString dir,QString name,int w,int h):dir(dir),name(name.replace(".txt","")),weight(w,h)
{
    qDebug()<<name.replace(".txt","");
    QFile file(dir);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    if(!file.exists())
    {
        qDebug()<<"Something wrong in Neuron::Neuron: file doesnt exists";
        //return;
    }
    QTextStream in(&file);
    QString line;
    QStringList stringlist;
    int i=0;
    line=in.readLine();
    while(!line.isNull())
    {
        if(line=="")
        {
            line=in.readLine();
            continue;
        }
        stringlist=line.split(" ");
        for(int j=0;j<stringlist.size();j++)
        {
            if(j==w)
                break;
            if(stringlist[j]!="")
            {
                weight[i][j]=stringlist[j].toDouble();
            }
        }
        i++;
        if(i==h)
            break;
        line=in.readLine();

    }

    QString text;
    for(int i=0;i<h;i++)
    {
        text="";
        for(int j=0;j<w;j++)
            text+=QString::number(weight[i][j])+" ";
        //qDebug()<<text;
    }
    file.close();
    qDebug()<<"---------------------------------";
    Save();

}

Neuron::Neuron()
{

}

void Neuron::Initialization(QString _dir, QString _name, int w, int h)
{
    dir=_dir;
    name=_name.replace(".txt","");
    weight.Initialization(w,h);

    qDebug()<<name.replace(".txt","");
    QFile file(dir);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    if(!file.exists())
    {
        qDebug()<<"Something wrong: file doesnt exists";
        return;
    }
    QTextStream in(&file);
    QString line;
    QStringList stringlist;
    int i=0;
    line=in.readLine();
    while(!line.isNull())
    {
        if(line=="")
        {
            line=in.readLine();
            continue;
        }
        stringlist=line.split(" ");
        for(int j=0;j<stringlist.size();j++)
        {
            if(j==w)
                break;
            if(stringlist[j]!="")
            {
                weight[i][j]=stringlist[j].toDouble();
            }
        }
        i++;
        if(i==h)
            break;
        line=in.readLine();

    }

    QString text;
    for(int i=0;i<h;i++)
    {
        text="";
        for(int j=0;j<w;j++)
            text+=QString::number(weight[i][j])+" ";
        //qDebug()<<text;
    }
    file.close();
    qDebug()<<"---------------------------------";
    Save();

}

void Neuron::Save()
{
    QFile file(dir);
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out(&file);
    //qDebug()<<"weight size:"<<weight.h()<<"X"<<weight.w();

    for(int i=0;i<weight.h();i++)
    {
        for(int j=0;j<weight.w();j++)
        {
            //qDebug()<<"Hi"<<QString::number(weight[i][j]);
            out<<QString::number(weight[i][j])<<" ";
        }
        out<<"\n";
    }
    file.close();

}

void Neuron::operator =(Neuron b)
{
    if(this==&b)
        return;
    weight=b.weight;
    name=b.name;
    dir=b.dir;
}
