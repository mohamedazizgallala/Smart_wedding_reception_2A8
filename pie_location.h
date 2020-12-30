#ifndef PIE_H
#define PIE_H
#include <QPieSeries>
#include <QChart>
#include <QPieSlice>
#include <QChartView>
#include <QDialog>
#include "car.h"
using namespace QtCharts;
namespace Ui {
class pie;
}

class pie : public QDialog
{
    Q_OBJECT

public:
    explicit pie(QWidget *parent = nullptr);
    ~pie();

private:
    Ui::pie *ui;
    car temp_car;
};

#endif // PIE_H
