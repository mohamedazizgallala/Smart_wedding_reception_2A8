#include "pie.h"
#include "ui_pie.h"
#include "car.h"

pie::pie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pie)
{
    ui->setupUi(this);
    QPieSeries *series_pie = new QPieSeries();

     series_pie->append("rouge",temp_car.count_couleur("rouge"));
      series_pie->append("bleu", temp_car.count_couleur("bleu"));
      series_pie->append("blanc", temp_car.count_couleur("blanc"));
      series_pie->append("noir", temp_car.count_couleur("noir"));
      series_pie->append("vert", temp_car.count_couleur("vert"));
      series_pie->append("gris", temp_car.count_couleur("gris"));
      series_pie->append("jaune", temp_car.count_couleur("jaune"));
      series_pie->append("rose", temp_car.count_couleur("rose"));



      QPieSlice *slice = series_pie->slices().at(1);
      slice->setExploded(true);
      slice->setLabelVisible(true);
      slice->setPen(QPen(Qt::blue, 2));
      slice->setBrush(Qt::blue);

      slice = series_pie->slices().at(0);
      slice->setExploded(true);
      slice->setLabelVisible(true);
      slice->setPen(QPen(Qt::red, 2));
      slice->setBrush(Qt::red);

      slice = series_pie->slices().at(2);
      slice->setExploded(true);
      slice->setLabelVisible(true);
      slice->setPen(QPen(Qt::white, 2));
      slice->setBrush(Qt::white);

      slice = series_pie->slices().at(3);
      slice->setExploded(true);
      slice->setLabelVisible(true);
      slice->setPen(QPen(Qt::black, 2));
      slice->setBrush(Qt::black);

      slice = series_pie->slices().at(4);
      slice->setExploded(true);
      slice->setLabelVisible(true);
      slice->setPen(QPen(Qt::green, 2));
      slice->setBrush(Qt::green);

      slice = series_pie->slices().at(5);
      slice->setExploded(true);
      slice->setLabelVisible(true);
      slice->setPen(QPen(Qt::gray, 2));
      slice->setBrush(Qt::gray);

      slice = series_pie->slices().at(6);
      slice->setExploded(true);
      slice->setLabelVisible(true);
      slice->setPen(QPen(Qt::yellow, 2));
      slice->setBrush(Qt::yellow);

      slice = series_pie->slices().at(7);
      slice->setExploded(true);
      slice->setLabelVisible(true);
      slice->setPen(QPen(Qt::magenta, 2));
      slice->setBrush(Qt::magenta);


      QChart *chart_pie = new QChart();
      chart_pie->addSeries(series_pie);
      chart_pie->setTitle("Stats sur les voitures");


      QChartView *chartview_pie = new QChartView(chart_pie);


      chartview_pie->setParent(this);

}

pie::~pie()
{
    delete ui;
}
