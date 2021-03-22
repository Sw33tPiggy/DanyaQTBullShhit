#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString str = "";
    for(int i = 0; i< 26; i++){
        str += QString(char('A' + i));
    }
    ui->label->setText(str);

    model1 = new QStringListModel(this);
    model2 = new QStringListModel(this);
    dateModel = new QStringListModel(this);


    stringList1.push_back("A");
    stringList1.push_back("B");
    stringList1.push_back("C");
    stringList1.push_back("D");


    ui->listView->setModel(model1);
    ui->listView_2->setModel(model2);
    ui->listView_3->setModel(dateModel);

    UpdateListViews();

    for(int i = 0; i< 26; i++){
        alphabet.push_back(char('A' + i));
    }

    ui->label_19->setText(QString(charForShifting));
    ui->label_21->setNum((intForShifting));
    ui->label_23->setText(QString::fromStdString(bitset.to_string()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString str = "";
    for(int i = 0; i< alphabet.size(); i++){
        str += alphabet[i];
    }
    ui->label->setText(str);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString str = "";
    ui->label->setText(str);
    for(int i = alphabet.size()-1; i>=0; i--){
        str += alphabet[i];

    }
    ui->label->setText(str);

//    QPropertyAnimation anim1(ui->label, "text");
//    anim1.setDuration(3000);
//    anim1.setStartValue(QString(""));
//    anim1.setEndValue(str);
//    anim1.start();

}

void MainWindow::on_lineEdit_returnPressed()
{
    AddFruit();
}

void MainWindow::AddFruit(){
    auto str = ui->lineEdit->text().trimmed();
    if(!str.isEmpty()){
        stringList1.push_back(str.toStdString());
        ui->lineEdit->setText("");
        UpdateListViews();
    }

}

void MainWindow::on_pushButton_5_clicked()
{
    ShouldRemoveCitrus = !ShouldRemoveCitrus;
    UpdateListViews();
}

void MainWindow::on_pushButton_4_clicked()
{
    ShouldSort = !ShouldSort;
    UpdateListViews();
}

void MainWindow::on_pushButton_3_clicked()
{
    ShoulRemoveA = !ShoulRemoveA;
    UpdateListViews();
}

void MainWindow::UpdateListViews(){
    QStringList qStringList1;
    QStringList qStringList2;
    for(int i = 0; i< stringList1.size(); i++){
        auto s = stringList1[i];
        if(!(ShoulRemoveA && (s[0]=='A' or s[0]=='a') )){
                qStringList2 << QString::fromStdString(s);
        }
        qStringList1 << QString::fromStdString(s);
    }
    if(ShouldSort){
        qStringList2.sort();
    }

    model1->setStringList(qStringList1);
    model2->setStringList(qStringList2);
}

void MainWindow::AddDate()
{
    auto str = ui->lineEdit_2->text().trimmed();
    if(!str.isEmpty()){
        auto parsedDate = formator.parse(str.toStdString());
        if(parsedDate.length() > 0){
            dates.push_back(parsedDate);
        }

        UpdateListDatesView();

    }
    ui->lineEdit_2->setText("");
}

void MainWindow::UpdateListDatesView(){
    QStringList qStringList;
    for(int i = 0; i< dates.size(); i++){
        auto s = dates[i];

        qStringList << QString::fromStdString(s);
    }

    qStringList.sort();


    dateModel->setStringList(qStringList);
}

void  MainWindow::on_lineEdit_2_returnPressed(){
    AddDate();
}

void MainWindow::on_lineEdit_3_returnPressed()
{
    AddBitSet();
}

void MainWindow::AddBitSet(){
    auto str = ui->lineEdit_3->text().trimmed().toStdString();
    if(str.length()==12){
        try {
            auto bitset = std::bitset<12>(str);
            if(bitset.count() >= 8){
                eightOrMore ++;
            }
            if(bitset.all()){
                all12 ++;
            }
            if(bitset.none()){
                never++;
            }
            ui->lineEdit_3->setText("");
            bitSetCounter++;
        } catch (std::invalid_argument) {

        }
    }
    ui->label_5->setText(QString::number(all12));
    ui->label_7->setText(QString::number(eightOrMore));
    ui->label_9->setText(QString::number(never));
    ui->label_10->setText(QString::number(bitSetCounter));
}

void MainWindow::RunVectorListTest(int n){
    using std::chrono::high_resolution_clock;
        using std::chrono::duration_cast;
        using std::chrono::duration;
        using std::chrono::nanoseconds;

    qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);
   auto TestVector = vector<int>(n);
   auto TestList = list<int>(n);

  auto t1 = high_resolution_clock::now();
   for(int i = 0; i< n*100; i++){
        int index = qrand() % n;
        int res = TestVector[index];
   }
   auto t2 = high_resolution_clock::now();
   ui->label_13->setText(QString::fromStdString( std::to_string( duration_cast<nanoseconds>(t2 - t1).count()) + "ns"));

   t1 = high_resolution_clock::now();
    for(int i = 0; i< n*100; i++){
         int index = qrand() % n;
         int res = TestList[index];
    }
    t2 = high_resolution_clock::now();
    ui->label_15->setText(QString::fromStdString( std::to_string( duration_cast<nanoseconds>(t2 - t1).count()) + "ns"));
}

void MainWindow::on_pushButton_10_pressed()
{
    int n = ui->spinBox->value();
    RunVectorListTest(n);
}

void MainWindow::on_pushButton_11_pressed()
{
    auto squares = vector<int>(100);
    for(int i = 0; i<100; i++){
        squares.push_back(i * i);
    }

    struct Functor {
        QListWidget * list;
        void operator()(int i){
            list->addItem(QString::number(i));
//            std::cout << "olo";
        }
    };

    Functor functor1;
    functor1.list = ui->listWidget;
    std::for_each(squares.begin(), squares.end(), functor1);

    auto roots = vector<int>(100);
    std::for_each(squares.begin(), squares.end(), [&](int i){
        roots.push_back(sqrt(i));
    });

    functor1.list = ui->listWidget_2;
    std::for_each(roots.begin(), roots.end(), functor1);
}


void MainWindow::ShiftLeft(){

    struct Shifter {
        char operator()(char &a){
            a = a << 1;
        }
        int operator()(int &a){
            a = a << 1;
        }
        std::bitset<67> operator()(std::bitset<67> &a){
            a = a << 1;
        }
    };
    Shifter shifter;
    shifter(bitset);
    shifter(charForShifting);
    shifter(intForShifting);
}

void MainWindow::ShiftRight(){

    struct Shifter {
        char operator()(char &a){
            a = a >> 1;
        }
        int operator()(int &a){
            a = a >> 1;
        }
        std::bitset<67> operator()(std::bitset<67> &a){
            a = a >> 1;
        }
    };

    Shifter shifter;
    shifter(bitset);
    shifter(charForShifting);
    shifter(intForShifting);
}

void MainWindow::on_pushButton_12_pressed()
{
    ShiftLeft();
    ui->label_19->setText(QString(charForShifting));
    ui->label_21->setNum((intForShifting));
    ui->label_23->setText(QString::fromStdString(bitset.to_string()));
}

void MainWindow::on_pushButton_13_pressed()
{
    ShiftRight();
    ui->label_19->setText(QString(charForShifting));
    ui->label_21->setNum(intForShifting);
    ui->label_23->setText(QString::fromStdString(bitset.to_string()));
}

void MainWindow::on_pushButton_14_pressed()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Load books"), "",
            tr("Address Book (*.txt);;All Files (*)"));

    if (fileName.isEmpty())
            return;
        else {
            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly)) {
                QMessageBox::information(this, tr("Unable to open file"),
                    file.errorString());
                return;
            }
            QTextStream instream(&file);
            QString line;
            int counter = 0;
            int rowCounter = 0;
            do {
                if(counter > 3){
                    counter = 0;
                    rowCounter ++;
                }
                line = instream.readLine();
                ui->tableWidget->setItem(rowCounter, counter, new QTableWidgetItem(line));
                counter++;
            } while (!line.isNull());
         }
}
