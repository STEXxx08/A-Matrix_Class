#include "matrix_fin.h"
using namespace std;


uchar* uchar_ptr::get(){
    return data;
}
uchar_ptr::uchar_ptr(uchar* data):ref_time(new size_t(1)){this->data = data;data = NULL;}
uchar_ptr::uchar_ptr(uchar_ptr & another):data(another.data),ref_time(another.ref_time){*ref_time++;}
uchar_ptr & uchar_ptr::operator=(uchar_ptr & another){
    if (this != &another) {
        if (--(*ref_time) == 0) {
            delete data;
            delete ref_time;
        }
        this->data = another.data;
        this->ref_time = another.ref_time;
        ++*ref_time;
    }
    return *this;
}
uchar_ptr::~uchar_ptr(){
    if(--*ref_time==0){
        delete data;
        delete ref_time;
    }
}
short* short_ptr::get(){
    return data;
}
short_ptr::short_ptr(short* data):ref_time(new size_t(1)){this->data = data;data = NULL;}
short_ptr::short_ptr(short_ptr & another):data(another.data),ref_time(another.ref_time){*ref_time++;}
short_ptr & short_ptr::operator=(short_ptr & another){
    if (this != &another) {
        if (--(*ref_time) == 0) {
            delete data;
            delete ref_time;
        }
        this->data = another.data;
        this->ref_time = another.ref_time;
        ++*ref_time;
    }
    return *this;
}
short_ptr::~short_ptr(){
    if(--*ref_time==0){
        delete data;
        delete ref_time;
    }
}


int* int_ptr::get(){
    return data;
}
int_ptr::int_ptr(int* data):ref_time(new size_t(1)){this->data = data;data = NULL;}
int_ptr::int_ptr(int_ptr & another):data(another.data),ref_time(another.ref_time){*ref_time++;}
int_ptr & int_ptr::operator=(int_ptr & another){
    if (this != &another) {
        if (--(*ref_time) == 0) {
            delete data;
            delete ref_time;
        }
        this->data = another.data;
        this->ref_time = another.ref_time;
        ++*ref_time;
    }
    return *this;
}
int_ptr::~int_ptr(){
    if(--*ref_time==0){
        delete data;
        delete ref_time;
    }
}


float* float_ptr::get(){
    return data;
}
float_ptr::float_ptr(float* data):ref_time(new size_t(1)){this->data = data;data = NULL;}
float_ptr::float_ptr(float_ptr & another):data(another.data),ref_time(another.ref_time){*ref_time++;}
float_ptr & float_ptr::operator=(float_ptr & another){
    if (this != &another) {
        if (--(*ref_time) == 0) {
            delete data;
            delete ref_time;
        }
        this->data = another.data;
        this->ref_time = another.ref_time;
        ++*ref_time;
    }
    return *this;
}
float_ptr::~float_ptr(){
    if(--*ref_time==0){
        delete data;
        delete ref_time;
    }
}


double* double_ptr::get(){
    return data;
}
double_ptr::double_ptr(double* data):ref_time(new size_t(1)){this->data = data;data = NULL;}
double_ptr::double_ptr(double_ptr & another):data(another.data),ref_time(another.ref_time){++*ref_time;}
double_ptr & double_ptr::operator=(double_ptr & another){
    if (this != &another) {
        if (--(*ref_time) == 0) {
            delete data;
            delete ref_time;
        }
        this->data = another.data;
        this->ref_time = another.ref_time;
        ++*ref_time;
    }
    return *this;
}
double_ptr::~double_ptr(){
    if(--*ref_time==0){
        delete data;
        delete ref_time;
    }
}


Matrix::Matrix(size_t rows,size_t cols):rows(rows),cols(cols){}

Matrix & Matrix::operator=(Matrix & another){
        this->rows = another.getRows();
        this->cols = another.getCols();
        return *this;
}
 int Matrix::operator==(Matrix& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            return 0;
        }
        return 1;
}
 int Matrix::operator!=(Matrix& another){
        return !(*this==another);
}
 Matrix& Matrix::operator+(Matrix& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        Matrix * output = new Matrix(rows,cols);
        return *output;
}
Matrix& Matrix::operator+(double c){return *this;}
Matrix& Matrix::operator+(float c){return *this;}
Matrix& Matrix::operator+(int c){return *this;}
Matrix& Matrix::operator+(short c){return *this;}
Matrix& Matrix::operator+(uchar c){return *this;}
Matrix& Matrix::operator+=(Matrix& another){return *this;}
template <typename T>
Matrix& Matrix::operator+=(T c){
        switch (this->MatrixType){
            case(0):{
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->getUCharDataValue()[loc]+=(uchar)c;
                    }
                }
                return *this;
            }
            case(1):{
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->getShortDataValue()[loc]+=(short)c;
                    }
                }
                return *this;
            }
            case(2):{
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->getIntDataValue()[loc]+=(int)c;
                    }
                }
                return *this;
            }
            case(3):{
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->getFloatDataValue()[loc]+=(float)c;
                    }
                }
                return *this;
            }
            case(4):{
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->getDoubleDataValue()[loc]+=(double)c;
                    }
                }
                return *this;
            }
            default:{
                return *this;
            }
        }
}
Matrix& Matrix::operator-(Matrix& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相减矩阵形状不相同！");
        }
        Matrix * output = new Matrix(rows,cols);
        return *output;
}
Matrix& Matrix::operator-(double c){return *this;}
Matrix& Matrix::operator-(float c){return *this;}
Matrix& Matrix::operator-(int c){return *this;}
Matrix& Matrix::operator-(short c){return *this;}
Matrix& Matrix::operator-(uchar c){return *this;}
Matrix& Matrix::operator-=(Matrix& another){return *this;}
template <typename T>
Matrix& Matrix::operator-=(T c){
        switch (this->MatrixType){
            case(0):{
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->getUCharDataValue()[loc]-=(uchar)c;
                    }
                }
                return *this;
            }
            case(1):{
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->getShortDataValue()[loc]-=(short)c;
                    }
                }
                return *this;
            }
            case(2):{
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->getIntDataValue()[loc]-=(int)c;
                    }
                }
                return *this;
            }
            case(3):{
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->getFloatDataValue()[loc]-=(float)c;
                    }
                }
                return *this;
            }
            case(4):{
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->getDoubleDataValue()[loc]-=(double)c;
                    }
                }
                return *this;
            }
            default:{
                return *this;
            }
        }
}
Matrix& Matrix::operator*(Matrix& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相乘矩阵形状不相同！");
        }
        Matrix * output = new Matrix(rows,cols);
        return *output;
}
Matrix& Matrix::operator*(double c){return *this;}
Matrix& Matrix::operator*(float c){return *this;}
Matrix& Matrix::operator*(int c){return *this;}
Matrix& Matrix::operator*(short c){return *this;}
Matrix& Matrix::operator*(uchar c){return *this;}
Matrix& Matrix::operator*=(Matrix& another){return *this;}
template <typename T>
Matrix& Matrix::operator*=(T c){
        switch (this->MatrixType){
            case(0):{
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->getUCharDataValue()[loc]*=(uchar)c;
                    }
                }
                return *this;
            }
            case(1):{
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->getShortDataValue()[loc]*=(short)c;
                    }
                }
                return *this;
            }
            case(2):{
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->getIntDataValue()[loc]*=(int)c;
                    }
                }
                return *this;
            }
            case(3):{
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->getFloatDataValue()[loc]*=(float)c;
                    }
                }
                return *this;
            }
            case(4):{
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->getDoubleDataValue()[loc]*=(double)c;
                    }
                }
                return *this;
            }
            default:{
                return *this;
            }
        }
}
Matrix& Matrix::operator/(Matrix& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相除矩阵形状不相同！");
        }
        Matrix * output = new Matrix(rows,cols);
        return *output;
}
Matrix& Matrix::operator/(double c){return *this;}
Matrix& Matrix::operator/(float c){return *this;}
Matrix& Matrix::operator/(int c){return *this;}
Matrix& Matrix::operator/(short c){return *this;}
Matrix& Matrix::operator/(uchar c){return *this;}
Matrix& Matrix::operator/=(Matrix& another){return *this;}
template <typename T>
Matrix& Matrix::operator/=(T c){
        switch (this->MatrixType){
            case(0):{
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->getUCharDataValue()[loc]/=(uchar)c;
                    }
                }
                return *this;
            }
            case(1):{
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->getShortDataValue()[loc]/=(short)c;
                    }
                }
                return *this;
            }
            case(2):{
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->getIntDataValue()[loc]/=(int)c;
                    }
                }
                return *this;
            }
            case(3):{
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->getFloatDataValue()[loc]/=(float)c;
                    }
                }
                return *this;
            }
            case(4):{
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->getDoubleDataValue()[loc]/=(double)c;
                    }
                }
                return *this;
            }
            default:{
                return *this;
            }
        }
}
std::ostream & operator<<(std::ostream & os, Matrix& m){
        std::string str = "";
        switch (m.getMatrixType()){
            case(0):{
                uchar* raw = m.getUCharDataValue();
                for(size_t i=0;i<m.getRows();i++){
                    for(size_t j=0;j<m.getCols();j++){
                        str =str + std::to_string(raw[i*m.getCols()+j]) + '\t';
                }
                    str += '\n';
                }
                str = str + '(' + std::to_string(m.getRows()) + " rows," + std::to_string(m.getCols()) + " cols,unsigned char)";
                break;
            }
            case(1):{
                short* raw = m.getShortDataValue();
                for(size_t i=0;i<m.getRows();i++){
                    for(size_t j=0;j<m.getCols();j++){
                        str =str + std::to_string(raw[i*m.getCols()+j]) + '\t';
                }
                    str += '\n';
                }
                str = str + '(' + std::to_string(m.getRows()) + " rows," + std::to_string(m.getCols()) + " cols,short)";
                break;
            }
            case(2):{
                int* raw = m.getIntDataValue();
                for(size_t i=0;i<m.getRows();i++){
                    for(size_t j=0;j<m.getCols();j++){
                        str =str + std::to_string(raw[i*m.getCols()+j]) + '\t';
                }
                    str += '\n';
                }
                str = str + '(' + std::to_string(m.getRows()) + " rows," + std::to_string(m.getCols()) + " cols,int)";
                break;
            }
            case(3):{
                float* raw = m.getFloatDataValue();
                for(size_t i=0;i<m.getRows();i++){
                    for(size_t j=0;j<m.getCols();j++){
                        str =str + std::to_string(raw[i*m.getCols()+j]) + '\t';
                }
                    str += '\n';
                }
                str = str + '(' + std::to_string(m.getRows()) + " rows," + std::to_string(m.getCols()) + " cols,float)";
                break;
            }
            case(4):{
                double* raw = m.getDoubleDataValue();
                for(size_t i=0;i<m.getRows();i++){
                    for(size_t j=0;j<m.getCols();j++){
                        str =str + std::to_string(raw[i*m.getCols()+j]) + '\t';
                }
                    str += '\n';
                }
                str = str + '(' + std::to_string(m.getRows()) + " rows," + std::to_string(m.getCols()) + " cols,double)";
                break;
            }
            default:{
                str += "当前无存储矩阵\n";
                str = str + '(' + std::to_string(m.getRows()) + " rows," + std::to_string(m.getCols()) + " cols)";
                break;
            }
        }
        os << str;
        return os;
}
std::istream & operator>>(std::istream & is, Matrix& m){
        switch (m.getMatrixType()){
            case(0):{
                uchar* raw = m.getUCharDataValue();
                for(size_t i=0;i<m.getRows()*m.getCols();i++){
                    is >> raw[i];
                    is.ignore(1);
                }
                break;
            }
            case(1):{
                short* raw = m.getShortDataValue();
                for(size_t i=0;i<m.getRows()*m.getCols();i++){
                    is >> raw[i];
                    is.ignore(1);
                }
                break;
            }
            case(2):{
                int* raw = m.getIntDataValue();
                for(size_t i=0;i<m.getRows()*m.getCols();i++){
                    is >> raw[i];
                    is.ignore(1);
                }
                break;
            }
            case(3):{
                float* raw = m.getFloatDataValue();
                for(size_t i=0;i<m.getRows()*m.getCols();i++){
                    is >> raw[i];
                    is.ignore(1);
                }
                break;
            }
            case(4):{
                double* raw = m.getDoubleDataValue();
                for(size_t i=0;i<m.getRows()*m.getCols();i++){
                    is >> raw[i];
                    is.ignore(1);
                }
                break;
            }
            default:{
                break;
            }
        }
        return is;
}
Matrix& Matrix::dot(Matrix& another){return *this;};
template <typename T>
int Matrix::edit(size_t i,size_t j,T datain){
        size_t loc = (i-1)*cols+(j-1);
        if(loc<rows*cols){
            switch (this->MatrixType){
                case(0):{
                    this->getUCharDataValue()[loc] = (uchar)datain;
                    break;
                }
                case(1):{
                    this->getShortDataValue()[loc] = (short)datain;
                    break;
                }
                case(2):{
                    this->getIntDataValue()[loc] = (int)datain;
                    break;
                }
                case(3):{
                    this->getFloatDataValue()[loc] = (float)datain;
                    break;
                }
                case(4):{
                    this->getDoubleDataValue()[loc] = (double)datain;
                    break;
                }
                default:{
                    break;
                }
            }
            return 1;
        }else{
            throw invalid_argument("error：修改的位置超过矩阵大小");
            return 0;
        }
}
template <typename T>
int Matrix::add(size_t i,size_t j,T datain){
        size_t loc = (i-1)*cols+(j-1);
        if(loc<rows*cols){
            switch (this->MatrixType){
                case(0):{
                    this->getUCharDataValue()[loc] += (uchar)datain;
                    break;
                }
                case(1):{
                    this->getShortDataValue()[loc] += (short)datain;
                    break;
                }
                case(2):{
                    this->getIntDataValue()[loc] += (int)datain;
                    break;
                }
                case(3):{
                    this->getFloatDataValue()[loc] += (float)datain;
                    break;
                }
                case(4):{
                    this->getDoubleDataValue()[loc] += (double)datain;
                    break;
                }
                default:{
                    break;
                }
            }
            return 1;
        }else{
            throw invalid_argument("error：修改的位置超过矩阵大小");
            return 0;
        }
}
template <typename T>
int Matrix::minus(size_t i,size_t j,T datain){
        size_t loc = (i-1)*cols+(j-1);
        if(loc<rows*cols){
            switch (this->MatrixType){
                case(0):{
                    this->getUCharDataValue()[loc] -= (uchar)datain;
                    break;
                }
                case(1):{
                    this->getShortDataValue()[loc] -= (short)datain;
                    break;
                }
                case(2):{
                    this->getIntDataValue()[loc] -= (int)datain;
                    break;
                }
                case(3):{
                    this->getFloatDataValue()[loc] -= (float)datain;
                    break;
                }
                case(4):{
                    this->getDoubleDataValue()[loc] -= (double)datain;
                    break;
                }
                default:{
                    break;
                }
            }
            return 1;
        }else{
            throw invalid_argument("error：修改的位置超过矩阵大小");
            return 0;
        }
}
template <typename T>
int Matrix::mul(size_t i,size_t j,T datain){
        size_t loc = (i-1)*cols+(j-1);
        if(loc<rows*cols){
            switch (this->MatrixType){
                case(0):{
                    this->getUCharDataValue()[loc] *= (uchar)datain;
                    break;
                }
                case(1):{
                    this->getShortDataValue()[loc] *= (short)datain;
                    break;
                }
                case(2):{
                    this->getIntDataValue()[loc] *= (int)datain;
                    break;
                }
                case(3):{
                    this->getFloatDataValue()[loc] *= (float)datain;
                    break;
                }
                case(4):{
                    this->getDoubleDataValue()[loc] *= (double)datain;
                    break;
                }
                default:{
                    break;
                }
            }
            return 1;
        }else{
            throw invalid_argument("error：修改的位置超过矩阵大小");
            return 0;
        }
}
template <typename T>
int Matrix::div(size_t i,size_t j,T datain){
        size_t loc = (i-1)*cols+(j-1);
        if(loc<rows*cols){
            switch (this->MatrixType){
                case(0):{
                    this->getUCharDataValue()[loc] /= (uchar)datain;
                    break;
                }
                case(1):{
                    this->getShortDataValue()[loc] /= (short)datain;
                    break;
                }
                case(2):{
                    this->getIntDataValue()[loc] /= (int)datain;
                    break;
                }
                case(3):{
                    this->getFloatDataValue()[loc] /= (float)datain;
                    break;
                }
                case(4):{
                    this->getDoubleDataValue()[loc] /= (double)datain;
                    break;
                }
                default:{
                    break;
                }
            }
            return 1;
        }else{
            throw invalid_argument("error：修改的位置超过矩阵大小");
            return 0;
        }
}
void Matrix::show(){cout << "当前无存储矩阵" << endl;}
packed_ptr* Matrix::getData(){return NULL;}
uchar* Matrix::getUCharDataValue(){return NULL;}
short* Matrix::getShortDataValue(){return NULL;}
int* Matrix::getIntDataValue(){return NULL;}
float* Matrix::getFloatDataValue(){return NULL;}
double* Matrix::getDoubleDataValue(){return NULL;}
size_t Matrix::getRows(){return rows;}
size_t Matrix::getCols(){return cols;}
void Matrix::setRows(size_t rows){this->rows = rows;}
void Matrix::setCols(size_t rows){this->cols = cols;}
size_t Matrix::getMatrixType(){return MatrixType;}
void Matrix::zero(){}
void Matrix::clear(){
        this->rows = 0;
        this->cols = 0;
        this->MatrixType = -1;
}


Matrix_double::Matrix_double(size_t rows,size_t cols):Matrix(rows,cols),data(new double_ptr(new double[rows*cols])){MatrixType=4;zero();};
Matrix_double::Matrix_double(size_t rows,size_t cols,double* data):Matrix(rows,cols),data(new double_ptr(data)){MatrixType=4;}
Matrix_double::~Matrix_double(){delete data;}
Matrix& Matrix_double::operator=(Matrix& another){
        this->rows = another.getRows();
        this->cols = another.getCols();
        this->MatrixType = another.getMatrixType();
        delete this->data;
        this->data = new double_ptr(another.getDoubleDataValue());
        delete &another;
        return *this;
}
Matrix_double& Matrix_double::operator=(Matrix_double& another){
        this->rows = another.getRows();
        this->cols = another.getCols();
        this->MatrixType = another.getMatrixType();
        delete this->data;
        this->data = another.data;
        return *this;
}
int Matrix_double::operator==(Matrix& another){
        if(this->cols!=another.getCols()|| this->rows!=another.getRows() || this->MatrixType!=another.getMatrixType()){
            return 0;
        }
        double* data1 = this->data->get();
        double* data2 = another.getDoubleDataValue();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                if(data1[loc]!=data2[loc]){
                    return 0;
                }
            }
        }
        return 1;
}
int Matrix_double::operator!=(Matrix& another){
        return !(*this==another);
}
Matrix_double& Matrix_double::operator+(Matrix_double& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        Matrix_double * output = new Matrix_double(rows,cols);
        double* data1 = this->data->get();
        double* data2 = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=data1[loc]+data2[loc];
            }
        }
        return *output;
}
Matrix& Matrix_double::operator+(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        Matrix_double * output = new Matrix_double(rows,cols);
        double* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            default:{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
        }
        return *output;
}
Matrix_double& Matrix_double::operator+(double c){
    Matrix_double * output = new Matrix_double(rows,cols);
    for(size_t i=0;i<rows;i++){
        for(size_t j=0;j<cols;j++){
            size_t loc = i*cols+j;
            output->data->get()[loc]=this->data->get()[loc]+c;
        }
    }
    return *output;
}
Matrix_double& Matrix_double::operator+=(Matrix_double& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        double* dataA = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]+=dataA[loc];
            }
        }
        return *this;
}
Matrix& Matrix_double::operator+=(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(double)data2[loc];
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(double)data2[loc];
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(double)data2[loc];
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(double)data2[loc];
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(double)data2[loc];
                    }
                }
                break;
            }
            default:{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(double)data2[loc];
                    }
                }
                break;
            }
        }
        return *this;
}
Matrix_double& Matrix_double::operator+=(double c){
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]+=c;
            }
        }
        return *this;
}
Matrix_double& Matrix_double::operator-(Matrix_double& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相减矩阵形状不相同！");
        }
        Matrix_double * output = new Matrix_double(rows,cols);
        double* data1 = this->data->get();
        double* data2 = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=data1[loc]-data2[loc];
            }
        }
        return *output;
}
Matrix& Matrix_double::operator-(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相减矩阵形状不相同！");
        }
        Matrix_double * output = new Matrix_double(rows,cols);
        double* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            default:{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
        }
        return *output;
}
Matrix_double& Matrix_double::operator-(double c){
        Matrix_double * output = new Matrix_double(rows,cols);
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=this->data->get()[loc]-c;
            }
        }
        return *output;
}
Matrix_double& Matrix_double::operator-=(Matrix_double& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        double* dataA = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]-=dataA[loc];
            }
        }
        return *this;
}
Matrix& Matrix_double::operator-=(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(double)data2[loc];
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(double)data2[loc];
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(double)data2[loc];
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(double)data2[loc];
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(double)data2[loc];
                    }
                }
                break;
            }
            default:{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(double)data2[loc];
                    }
                }
                break;
            }
        }
        return *this;
}
Matrix_double& Matrix_double::operator-=(double c){
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]-=c;
            }
        }
        return *this;
}
Matrix_double& Matrix_double::operator*(Matrix_double& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相乘矩阵形状不相同！");
        }
        Matrix_double * output = new Matrix_double(rows,cols);
        double* data1 = this->data->get();
        double* data2 = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=data1[loc]*data2[loc];
            }
        }
        return *output;
}
Matrix& Matrix_double::operator*(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相乘矩阵形状不相同！");
        }
        Matrix_double * output = new Matrix_double(rows,cols);
        double* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            default:{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
        }
        return *output;
}
Matrix_double& Matrix_double::operator*(double c){
        Matrix_double * output = new Matrix_double(rows,cols);
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=this->data->get()[loc]*c;
            }
        }
        return *output;
}
Matrix_double& Matrix_double::operator*=(Matrix_double& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相乘矩阵形状不相同！");
        }
        double* dataA = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]*=dataA[loc];
            }
        }
        return *this;
}
Matrix& Matrix_double::operator*=(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相乘矩阵形状不相同！");
        }
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(double)data2[loc];
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(double)data2[loc];
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(double)data2[loc];
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(double)data2[loc];
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(double)data2[loc];
                    }
                }
                break;
            }
            default:{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(double)data2[loc];
                    }
                }
                break;
            }
        }
        return *this;
}
Matrix_double& Matrix_double::operator*=(double c){
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]*=c;
            }
        }
        return *this;
}
Matrix_double& Matrix_double::operator/(Matrix_double& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相除矩阵形状不相同！");
        }
        Matrix_double * output = new Matrix_double(rows,cols);
        double* data1 = this->data->get();
        double* data2 = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=data1[loc]/data2[loc];
            }
        }
        return *output;
}
Matrix& Matrix_double::operator/(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相除矩阵形状不相同！");
        }
        Matrix_double * output = new Matrix_double(rows,cols);
        double* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            default:{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(double)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
        }
        return *output;
}
Matrix_double& Matrix_double::operator/(double c){
        Matrix_double * output = new Matrix_double(rows,cols);
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=this->data->get()[loc]/c;
            }
        }
        return *output;
}
Matrix_double& Matrix_double::operator/=(Matrix_double& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相除矩阵形状不相同！");
        }
        double* dataA = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]/=dataA[loc];
            }
        }
        return *this;
}
Matrix& Matrix_double::operator/=(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相除矩阵形状不相同！");
        }
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(double)data2[loc];
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(double)data2[loc];
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(double)data2[loc];
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(double)data2[loc];
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(double)data2[loc];
                    }
                }
                break;
            }
            default:{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(double)data2[loc];
                    }
                }
                break;
            }
        }
        return *this;
}
Matrix_double& Matrix_double::operator/=(double c){
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]/=c;
            }
        }
        return *this;
}
Matrix& Matrix_double::dot(Matrix& another){
        if(this->cols!=another.getRows()){
            throw invalid_argument("error：矩阵形状无法进行点乘");
        }
        double* data1 = this->data->get();
        Matrix *output = new Matrix_double(this->rows,this->cols);
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                double sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(double) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getDoubleDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                double sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(double) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getDoubleDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                double sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(double) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getDoubleDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                double sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(double) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getDoubleDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                double sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(double) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getDoubleDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            default:{
                return *this;
            }
        }
}
void Matrix_double::show(){
        double* raw = data->get();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout << raw[i*cols+j] << '\t';
            }
            cout << endl;
        }
        cout  << '(' << rows << " rows," << cols << " cols,double)" << endl;
}
double_ptr* Matrix_double::getData(){
        return this->data;
}
double* Matrix_double::getDoubleDataValue(){
        return this->data->get();
}
void Matrix_double::zero(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                this->data->get()[i*cols+j] = 0;
            }
        }
}
void Matrix_double::clear(){
        delete this->data;
        this->rows = 0;
        this->cols = 0;
        this->MatrixType = -1;
}


Matrix_float::Matrix_float(size_t rows,size_t cols):Matrix(rows,cols),data(new float_ptr(new float[rows*cols])){MatrixType=3;zero();};
Matrix_float::Matrix_float(size_t rows,size_t cols,float* data):Matrix(rows,cols),data(new float_ptr(data)){MatrixType=3;}
Matrix_float::~Matrix_float(){delete data;}
Matrix& Matrix_float::operator=(Matrix& another){
        this->rows = another.getRows();
        this->cols = another.getCols();
        this->MatrixType = another.getMatrixType();
        delete this->data;
        this->data = new float_ptr(another.getFloatDataValue());
        delete &another;
        return *this;
}
Matrix_float& Matrix_float::operator=(Matrix_float& another){
        this->rows = another.getRows();
        this->cols = another.getCols();
        this->MatrixType = another.getMatrixType();
        delete this->data;
        this->data = another.data;
        return *this;
}
int Matrix_float::operator==(Matrix& another){
        if(this->cols!=another.getCols()|| this->rows!=another.getRows() || this->MatrixType!=another.getMatrixType()){
            return 0;
        }
        float* data1 = this->data->get();
        float* data2 = another.getFloatDataValue();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                if(data1[loc]!=data2[loc]){
                    return 0;
                }
            }
        }
        return 1;
}
int Matrix_float::operator!=(Matrix& another){
        return !(*this==another);
}
Matrix_float& Matrix_float::operator+(Matrix_float& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        Matrix_float * output = new Matrix_float(rows,cols);
        float* data1 = this->data->get();
        float* data2 = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=data1[loc]+data2[loc];
            }
        }
        return *output;
}
Matrix& Matrix_float::operator+(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        Matrix_float * output = new Matrix_float(rows,cols);
        float* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            default:{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
        }
        return *output;
}
Matrix_float& Matrix_float::operator+(float c){
        Matrix_float * output = new Matrix_float(rows,cols);
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=this->data->get()[loc]+c;
            }
        }
        return *output;
}
Matrix_float& Matrix_float::operator+(double c){
        Matrix_float * output = new Matrix_float(rows,cols);
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=this->data->get()[loc]+c;
            }
        }
        return *output;
}
Matrix_float& Matrix_float::operator+=(Matrix_float& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        float* dataA = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]+=dataA[loc];
            }
        }
        return *this;
}
Matrix& Matrix_float::operator+=(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(float)data2[loc];
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(float)data2[loc];
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(float)data2[loc];
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(float)data2[loc];
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(float)data2[loc];
                    }
                }
                break;
            }
            default:{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(float)data2[loc];
                    }
                }
                break;
            }
        }
        return *this;
}
Matrix_float& Matrix_float::operator+=(float c){
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]+=c;
            }
        }
        return *this;
}
Matrix_float& Matrix_float::operator+=(double c){
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]+=c;
            }
        }
        return *this;
}
Matrix_float& Matrix_float::operator-(Matrix_float& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相减矩阵形状不相同！");
        }
        Matrix_float * output = new Matrix_float(rows,cols);
        float* data1 = this->data->get();
        float* data2 = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=data1[loc]-data2[loc];
            }
        }
        return *output;
}
Matrix& Matrix_float::operator-(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相减矩阵形状不相同！");
        }
        Matrix_float * output = new Matrix_float(rows,cols);
        float* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            default:{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
        }
        return *output;
}
Matrix_float& Matrix_float::operator-(float c){
        Matrix_float * output = new Matrix_float(rows,cols);
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=this->data->get()[loc]-c;
            }
        }
        return *output;
}
Matrix_float& Matrix_float::operator-=(Matrix_float& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        float* dataA = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]-=dataA[loc];
            }
        }
        return *this;
}
Matrix& Matrix_float::operator-=(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(float)data2[loc];
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(float)data2[loc];
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(float)data2[loc];
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(float)data2[loc];
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(float)data2[loc];
                    }
                }
                break;
            }
            default:{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(float)data2[loc];
                    }
                }
                break;
            }
        }
        return *this;
}
Matrix_float& Matrix_float::operator-=(float c){
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]-=c;
            }
        }
        return *this;
}
Matrix_float& Matrix_float::operator*(Matrix_float& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相乘矩阵形状不相同！");
        }
        Matrix_float * output = new Matrix_float(rows,cols);
        float* data1 = this->data->get();
        float* data2 = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=data1[loc]*data2[loc];
            }
        }
        return *output;
}
Matrix& Matrix_float::operator*(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相乘矩阵形状不相同！");
        }
        Matrix_float * output = new Matrix_float(rows,cols);
        float* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            default:{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
        }
        return *output;
}
Matrix_float& Matrix_float::operator*(float c){
        Matrix_float * output = new Matrix_float(rows,cols);
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=this->data->get()[loc]*c;
            }
        }
        return *output;
}
Matrix_float& Matrix_float::operator*=(Matrix_float& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相乘矩阵形状不相同！");
        }
        float* dataA = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]*=dataA[loc];
            }
        }
        return *this;
}
Matrix& Matrix_float::operator*=(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相乘矩阵形状不相同！");
        }
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(float)data2[loc];
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(float)data2[loc];
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(float)data2[loc];
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(float)data2[loc];
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(float)data2[loc];
                    }
                }
                break;
            }
            default:{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(float)data2[loc];
                    }
                }
                break;
            }
        }
        return *this;
}
Matrix_float& Matrix_float::operator*=(float c){
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]*=c;
            }
        }
        return *this;
}
Matrix_float& Matrix_float::operator/(Matrix_float& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相除矩阵形状不相同！");
        }
        Matrix_float * output = new Matrix_float(rows,cols);
        float* data1 = this->data->get();
        float* data2 = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=data1[loc]/data2[loc];
            }
        }
        return *output;
}
Matrix& Matrix_float::operator/(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相除矩阵形状不相同！");
        }
        Matrix_float * output = new Matrix_float(rows,cols);
        float* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            default:{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(float)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
        }
        return *output;
}
Matrix_float& Matrix_float::operator/(float c){
        Matrix_float * output = new Matrix_float(rows,cols);
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=this->data->get()[loc]/c;
            }
        }
        return *output;
}
Matrix_float& Matrix_float::operator/=(Matrix_float& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相除矩阵形状不相同！");
        }
        float* dataA = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]/=dataA[loc];
            }
        }
        return *this;
}
Matrix& Matrix_float::operator/=(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相除矩阵形状不相同！");
        }
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(float)data2[loc];
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(float)data2[loc];
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(float)data2[loc];
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(float)data2[loc];
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(float)data2[loc];
                    }
                }
                break;
            }
            default:{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(float)data2[loc];
                    }
                }
                break;
            }
        }
        return *this;
}
Matrix_float& Matrix_float::operator/=(float c){
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]/=c;
            }
        }
        return *this;
}
Matrix& Matrix_float::dot(Matrix& another){
        if(this->cols!=another.getRows()){
            throw invalid_argument("error：矩阵形状无法进行点乘");
        }
        float* data1 = this->data->get();
        Matrix *output = new Matrix_double(this->rows,this->cols);
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                double sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(double) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getDoubleDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                double sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(double) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getDoubleDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                double sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(double) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getDoubleDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                double sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(double) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getDoubleDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                double sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(double) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getDoubleDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            default:{
                return *this;
            }
        }
}
void Matrix_float::show(){
        float* raw = data->get();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout << raw[i*cols+j] << '\t';
            }
            cout << endl;
        }
        cout  << '(' << rows << " rows," << cols << " cols,float)" << endl;
}
float_ptr* Matrix_float::getData(){
        return this->data;
}
float* Matrix_float::getFloatDataValue(){
        return this->data->get();
}
void Matrix_float::zero(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                this->data->get()[i*cols+j] = 0;
            }
        }
}
void Matrix_float::clear(){
        delete this->data;
        this->rows = 0;
        this->cols = 0;
        this->MatrixType = -1;
}


Matrix_int::Matrix_int(size_t rows,size_t cols):Matrix(rows,cols),data(new int_ptr(new int[rows*cols])){MatrixType=2;zero();};
Matrix_int::Matrix_int(size_t rows,size_t cols,int* data):Matrix(rows,cols),data(new int_ptr(data)){MatrixType=2;}
Matrix_int::~Matrix_int(){delete data;}
Matrix& Matrix_int::operator=(Matrix& another){
        this->rows = another.getRows();
        this->cols = another.getCols();
        this->MatrixType = another.getMatrixType();
        delete this->data;
        this->data = new int_ptr(another.getIntDataValue());
        delete &another;
        return *this;
}
Matrix_int& Matrix_int::operator=(Matrix_int& another){
        this->rows = another.getRows();
        this->cols = another.getCols();
        this->MatrixType = another.getMatrixType();
        delete this->data;
        this->data = another.data;
        return *this;
}
int Matrix_int::operator==(Matrix& another){
        if(this->cols!=another.getCols()|| this->rows!=another.getRows() || this->MatrixType!=another.getMatrixType()){
            return 0;
        }
        int* data1 = this->data->get();
        int* data2 = another.getIntDataValue();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int loc = i*cols+j;
                if(data1[loc]!=data2[loc]){
                    return 0;
                }
            }
        }
        
        return 1;
}
int Matrix_int::operator!=(Matrix& another){
        return !(*this==another);
}
Matrix_int& Matrix_int::operator+(Matrix_int& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        Matrix_int * output = new Matrix_int(rows,cols);
        int* data1 = this->data->get();
        int* data2 = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=data1[loc]+data2[loc];
            }
        }
        return *output;
}
Matrix& Matrix_int::operator+(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }

        Matrix_int * output = new Matrix_int(rows,cols);
        int* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            default:{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
        }
        return *output;
}
Matrix_int& Matrix_int::operator+(int c){
        Matrix_int * output = new Matrix_int(rows,cols);
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=this->data->get()[loc]+c;
            }
        }
        return *output;
}
Matrix_int& Matrix_int::operator+=(Matrix_int& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        int* dataA = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]+=dataA[loc];
            }
        }
        return *this;
}
Matrix& Matrix_int::operator+=(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(int)data2[loc];
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(int)data2[loc];
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(int)data2[loc];
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(int)data2[loc];
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(int)data2[loc];
                    }
                }
                break;
            }
            default:{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(int)data2[loc];
                    }
                }
                break;
            }
        }
        return *this;
}
Matrix_int& Matrix_int::operator+=(int c){
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]+=c;
            }
        }
        return *this;
}
Matrix_int& Matrix_int::operator-(Matrix_int& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相减矩阵形状不相同！");
        }
        Matrix_int * output = new Matrix_int(rows,cols);
        int* data1 = this->data->get();
        int* data2 = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=data1[loc]-data2[loc];
            }
        }
        return *output;
}
Matrix& Matrix_int::operator-(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相减矩阵形状不相同！");
        }
        Matrix_int * output = new Matrix_int(rows,cols);
        int* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            default:{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
        }
        return *output;
}
Matrix_int& Matrix_int::operator-(int c){
        Matrix_int * output = new Matrix_int(rows,cols);
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=this->data->get()[loc]-c;
            }
        }
        return *output;
}
Matrix_int& Matrix_int::operator-=(Matrix_int& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        int* dataA = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]-=dataA[loc];
            }
        }
        return *this;
}
Matrix& Matrix_int::operator-=(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(int)data2[loc];
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(int)data2[loc];
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(int)data2[loc];
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(int)data2[loc];
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(int)data2[loc];
                    }
                }
                break;
            }
            default:{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(int)data2[loc];
                    }
                }
                break;
            }
        }
        return *this;
}
Matrix_int& Matrix_int::operator-=(int c){
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]-=c;
            }
        }
        return *this;
}
Matrix_int& Matrix_int::operator*(Matrix_int& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相乘矩阵形状不相同！");
        }
        Matrix_int * output = new Matrix_int(rows,cols);
        int* data1 = this->data->get();
        int* data2 = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=data1[loc]*data2[loc];
            }
        }
        return *output;
}
Matrix& Matrix_int::operator*(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相乘矩阵形状不相同！");
        }

        Matrix_int * output = new Matrix_int(rows,cols);
        int* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            default:{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
        }
        return *output;
}
Matrix_int& Matrix_int::operator*(int c){
        Matrix_int * output = new Matrix_int(rows,cols);
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=this->data->get()[loc]*c;
            }
        }
        return *output;
}
Matrix_int& Matrix_int::operator*=(Matrix_int& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相乘矩阵形状不相同！");
        }
        int* dataA = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]*=dataA[loc];
            }
        }
        return *this;
}
Matrix& Matrix_int::operator*=(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相乘矩阵形状不相同！");
        }
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(int)data2[loc];
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(int)data2[loc];
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(int)data2[loc];
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(int)data2[loc];
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(int)data2[loc];
                    }
                }
                break;
            }
            default:{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(int)data2[loc];
                    }
                }
                break;
            }
        }
        return *this;
}
Matrix_int& Matrix_int::operator*=(int c){
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]*=c;
            }
        }
        return *this;
}
Matrix_int& Matrix_int::operator/(Matrix_int& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相除矩阵形状不相同！");
        }
        Matrix_int * output = new Matrix_int(rows,cols);
        int* data1 = this->data->get();
        int* data2 = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=data1[loc]/data2[loc];
            }
        }
        return *output;
}
Matrix& Matrix_int::operator/(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相除矩阵形状不相同！");
        }

        Matrix_int * output = new Matrix_int(rows,cols);
        int* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            default:{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(int)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
        }
        return *output;
}
Matrix_int& Matrix_int::operator/(int c){
        Matrix_int * output = new Matrix_int(rows,cols);
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=this->data->get()[loc]/c;
            }
        }
        return *output;
}
Matrix_int& Matrix_int::operator/=(Matrix_int& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相除矩阵形状不相同！");
        }
        int* dataA = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]/=dataA[loc];
            }
        }
        return *this;
}
Matrix& Matrix_int::operator/=(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相除矩阵形状不相同！");
        }
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(int)data2[loc];
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(int)data2[loc];
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(int)data2[loc];
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(int)data2[loc];
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(int)data2[loc];
                    }
                }
                break;
            }
            default:{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(int)data2[loc];
                    }
                }
                break;
            }
        }
        return *this;
}
Matrix_int& Matrix_int::operator/=(int c){
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]/=c;
            }
        }
        return *this;
}
Matrix& Matrix_int::dot(Matrix& another){
        if(this->cols!=another.getRows()){
            throw invalid_argument("error：矩阵形状无法进行点乘");
        }
        int* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                Matrix * output = new Matrix_int(this->rows,this->cols);
                int sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(int) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getIntDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                Matrix *output = new Matrix_int(this->rows,this->cols);
                int sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(int) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getIntDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                Matrix *output = new Matrix_int(this->rows,this->cols);
                int sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(int) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getIntDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                Matrix *output = new Matrix_double(this->rows,this->cols);
                double sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(double) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getDoubleDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                Matrix *output = new Matrix_double(this->rows,this->cols);
                double sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(double) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getDoubleDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            default:{
                return *this;
            }
        }
}
void Matrix_int::show(){
        int* raw = data->get();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout << raw[i*cols+j] << '\t';
            }
            cout << endl;
        }
        cout  << '(' << rows << " rows," << cols << " cols,int)" << endl;
}
int_ptr* Matrix_int::getData(){
            return this->data;
}
int * Matrix_int::getIntDataValue(){
        return this->data->get();
}
void Matrix_int::zero(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                this->data->get()[i*cols+j] = 0;
            }
        }
}
void Matrix_int::clear(){
        delete this->data;
        this->rows = 0;
        this->cols = 0;
        this->MatrixType = -1;
}


Matrix_short::Matrix_short(size_t rows,size_t cols):Matrix(rows,cols),data(new short_ptr(new short[rows*cols])){MatrixType=1;zero();};
Matrix_short::Matrix_short(size_t rows,size_t cols,short* data):Matrix(rows,cols),data(new short_ptr(data)){MatrixType=1;}
Matrix_short::~Matrix_short(){delete data;}
Matrix& Matrix_short::operator=(Matrix& another){
        this->rows = another.getRows();
        this->cols = another.getCols();
        this->MatrixType = another.getMatrixType();
        delete this->data;
        this->data = new short_ptr(another.getShortDataValue());
        delete &another;
        return *this;
}
Matrix_short& Matrix_short::operator=(Matrix_short& another){
        this->rows = another.getRows();
        this->cols = another.getCols();
        this->MatrixType = another.getMatrixType();
        delete this->data;
        this->data = another.data;
        return *this;
}
int Matrix_short::operator==(Matrix& another){
        if(this->cols!=another.getCols()|| this->rows!=another.getRows() || this->MatrixType!=another.getMatrixType()){
            return 0;
        }
        short* data1 = this->data->get();
        short* data2 = another.getShortDataValue();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                if(data1[loc]!=data2[loc]){
                    return 0;
                }
            }
        }
        return 1;
}
int Matrix_short::operator!=(Matrix& another){
        return !(*this==another);
}
Matrix_short& Matrix_short::operator+(Matrix_short& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        Matrix_short * output = new Matrix_short(rows,cols);
        short* data1 = this->data->get();
        short* data2 = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=data1[loc]+data2[loc];
            }
        }
        return *output;
}
Matrix& Matrix_short::operator+(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        Matrix_short * output = new Matrix_short(rows,cols);
        short* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            default:{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
        }
        return *output;
}
Matrix_short& Matrix_short::operator+(short c){
        Matrix_short * output = new Matrix_short(rows,cols);
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=this->data->get()[loc]+c;
            }
        }
        return *output;
}
Matrix_short& Matrix_short::operator+=(Matrix_short& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        short* dataA = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]+=dataA[loc];
            }
        }
        return *this;
}
Matrix& Matrix_short::operator+=(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(short)data2[loc];
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(short)data2[loc];
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(short)data2[loc];
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(short)data2[loc];
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(short)data2[loc];
                    }
                }
                break;
            }
            default:{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(short)data2[loc];
                    }
                }
                break;
            }
        }
        return *this;
}
Matrix_short& Matrix_short::operator+=(short c){
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]+=c;
            }
        }
        return *this;
}
Matrix_short& Matrix_short::operator-(Matrix_short& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相减矩阵形状不相同！");
        }
        Matrix_short * output = new Matrix_short(rows,cols);
        short* data1 = this->data->get();
        short* data2 = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=data1[loc]-data2[loc];
            }
        }
        return *output;
}
Matrix& Matrix_short::operator-(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相减矩阵形状不相同！");
        }

        Matrix_short * output = new Matrix_short(rows,cols);
        short* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            default:{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
        }
        return *output;
}
Matrix_short& Matrix_short::operator-(short c){
        Matrix_short * output = new Matrix_short(rows,cols);
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=this->data->get()[loc]-c;
            }
        }
        return *output;
}
Matrix_short& Matrix_short::operator-=(Matrix_short& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        short* dataA = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]-=dataA[loc];
            }
        }
        return *this;
}
Matrix& Matrix_short::operator-=(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(short)data2[loc];
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(short)data2[loc];
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(short)data2[loc];
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(short)data2[loc];
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(short)data2[loc];
                    }
                }
                break;
            }
            default:{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(short)data2[loc];
                    }
                }
                break;
            }
        }
        return *this;
}
Matrix_short& Matrix_short::operator-=(short c){
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]-=c;
            }
        }
        return *this;
}
Matrix_short& Matrix_short::operator*(Matrix_short& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相乘矩阵形状不相同！");
        }
        Matrix_short * output = new Matrix_short(rows,cols);
        short* data1 = this->data->get();
        short* data2 = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=data1[loc]*data2[loc];
            }
        }
        return *output;
}
Matrix& Matrix_short::operator*(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相乘矩阵形状不相同！");
        }
        Matrix_short * output = new Matrix_short(rows,cols);
        short* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            default:{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
        }
        return *output;
}
Matrix_short& Matrix_short::operator*(short c){
        Matrix_short * output = new Matrix_short(rows,cols);
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=this->data->get()[loc]*c;
            }
        }
        return *output;
}
Matrix_short& Matrix_short::operator*=(Matrix_short& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相乘矩阵形状不相同！");
        }
        short* dataA = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]*=dataA[loc];
            }
        }
        return *this;
}
Matrix& Matrix_short::operator*=(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相乘矩阵形状不相同！");
        }
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(short)data2[loc];
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(short)data2[loc];
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(short)data2[loc];
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(short)data2[loc];
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(short)data2[loc];
                    }
                }
                break;
            }
            default:{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(short)data2[loc];
                    }
                }
                break;
            }
        }
        return *this;
}
Matrix_short& Matrix_short::operator*=(short c){
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]*=c;
            }
        }
        return *this;
}
Matrix_short& Matrix_short::operator/(Matrix_short& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相除矩阵形状不相同！");
        }
        Matrix_short * output = new Matrix_short(rows,cols);
        short* data1 = this->data->get();
        short* data2 = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=data1[loc]/data2[loc];
            }
        }
        return *output;
}
Matrix& Matrix_short::operator/(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相除矩阵形状不相同！");
        }
        Matrix_short * output = new Matrix_short(rows,cols);
        short* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            default:{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(short)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
        }
        return *output;
}
Matrix_short& Matrix_short::operator/(short c){
        Matrix_short * output = new Matrix_short(rows,cols);
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=this->data->get()[loc]/c;
            }
        }
        return *output;
}
Matrix_short& Matrix_short::operator/=(Matrix_short& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相除矩阵形状不相同！");
        }
        short* dataA = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]/=dataA[loc];
            }
        }
        return *this;
}
Matrix& Matrix_short::operator/=(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相除矩阵形状不相同！");
        }
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(short)data2[loc];
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(short)data2[loc];
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(short)data2[loc];
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(short)data2[loc];
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(short)data2[loc];
                    }
                }
                break;
            }
            default:{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(short)data2[loc];
                    }
                }
                break;
            }
        }
        return *this;
}
Matrix_short& Matrix_short::operator/=(short c){
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]/=c;
            }
        }
        return *this;
}
Matrix& Matrix_short::dot(Matrix& another){
        if(this->cols!=another.getRows()){
            throw invalid_argument("error：矩阵形状无法进行点乘");
        }
        short* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                Matrix * output = new Matrix_int(this->rows,this->cols);
                int sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(int) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getIntDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                Matrix *output = new Matrix_int(this->rows,this->cols);
                int sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(int) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getIntDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                Matrix *output = new Matrix_int(this->rows,this->cols);
                int sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(int) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getIntDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                Matrix *output = new Matrix_double(this->rows,this->cols);
                double sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(double) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getDoubleDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                Matrix *output = new Matrix_double(this->rows,this->cols);
                double sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(double) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getDoubleDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            default:{
                return *this;
            }
        }
}
void Matrix_short::show(){
        short* raw = data->get();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout << raw[i*cols+j] << '\t';
            }
            cout << endl;
        }
        cout  << '(' << rows << " rows," << cols << " cols,short)" << endl;
}
short_ptr* Matrix_short::getData(){
            return this->data;
}
short* Matrix_short::getShortDataValue(){
        return this->data->get();
}
void Matrix_short::zero(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                this->data->get()[i*cols+j] = 0;
            }
        }
}
void Matrix_short::clear(){
        delete this->data;
        this->rows = 0;
        this->cols = 0;
        this->MatrixType = -1;
}


Matrix_uchar::Matrix_uchar(size_t rows,size_t cols):Matrix(rows,cols),data(new uchar_ptr(new uchar[rows*cols])){MatrixType=0;zero();};
Matrix_uchar::Matrix_uchar(size_t rows,size_t cols,uchar* data):Matrix(rows,cols),data(new uchar_ptr(data)){MatrixType=0;}
Matrix_uchar::~Matrix_uchar(){delete data;}
Matrix& Matrix_uchar::operator=(Matrix& another){
        this->rows = another.getRows();
        this->cols = another.getCols();
        this->MatrixType = another.getMatrixType();
        delete this->data;
        this->data = new uchar_ptr(another.getUCharDataValue());
        delete &another;
        return *this;
}
Matrix_uchar& Matrix_uchar::operator=(Matrix_uchar& another){
        this->rows = another.getRows();
        this->cols = another.getCols();
        this->MatrixType = another.getMatrixType();
        delete this->data;
        this->data = another.data;
        return *this;
}
int Matrix_uchar::operator==(Matrix& another){
        if(this->cols!=another.getCols()|| this->rows!=another.getRows() || this->MatrixType!=another.getMatrixType()){
            return 0;
        }
        uchar* data1 = this->data->get();
        uchar* data2 = another.getUCharDataValue();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                if(data1[loc]!=data2[loc]){
                    return 0;
                }
            }
        }
        return 1;
}
int Matrix_uchar::operator!=(Matrix& another){
        return !(*this==another);
}
Matrix_uchar& Matrix_uchar::operator+(Matrix_uchar& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        Matrix_uchar * output = new Matrix_uchar(rows,cols);
        uchar* data1 = this->data->get();
        uchar* data2 = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=data1[loc]+data2[loc];
            }
        }
        return *output;
}
Matrix& Matrix_uchar::operator+(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        if(another.getMatrixType()>2){
            throw invalid_argument("error:uchar类型与浮点数的运算不兼容！");
        }
        Matrix_uchar * output = new Matrix_uchar(rows,cols);
        uchar* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(uchar)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(uchar)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(uchar)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
            default:{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(uchar)(data1[loc]+data2[loc]);
                    }
                }
                break;
            }
        }
        return *output;
}
Matrix_uchar& Matrix_uchar::operator+(uchar c){
        Matrix_uchar * output = new Matrix_uchar(rows,cols);
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=this->data->get()[loc]+c;
            }
        }
        return *output;
}
Matrix_uchar& Matrix_uchar::operator+=(Matrix_uchar& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        uchar* dataA = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]+=dataA[loc];
            }
        }
        return *this;
}
Matrix& Matrix_uchar::operator+=(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(uchar)data2[loc];
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(uchar)data2[loc];
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(uchar)data2[loc];
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(uchar)data2[loc];
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(uchar)data2[loc];
                    }
                }
                break;
            }
            default:{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]+=(uchar)data2[loc];
                    }
                }
                break;
            }
        }
        return *this;
}
Matrix_uchar& Matrix_uchar::operator+=(uchar c){
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]+=c;
            }
        }
        return *this;
}
Matrix_uchar& Matrix_uchar::operator-(Matrix_uchar& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相减矩阵形状不相同！");
        }
        Matrix_uchar * output = new Matrix_uchar(rows,cols);
        uchar* data1 = this->data->get();
        uchar* data2 = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=data1[loc]-data2[loc];
            }
        }
        return *output;
}
Matrix& Matrix_uchar::operator-(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相减矩阵形状不相同！");
        }
        if(another.getMatrixType()>2){
            throw invalid_argument("error:uchar类型与浮点数的运算不兼容！");
        }
        Matrix_uchar * output = new Matrix_uchar(rows,cols);
        uchar* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(uchar)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(uchar)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(uchar)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
            default:{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(uchar)(data1[loc]-data2[loc]);
                    }
                }
                break;
            }
        }
        return *output;
}
Matrix_uchar& Matrix_uchar::operator-(uchar c){
        Matrix_uchar * output = new Matrix_uchar(rows,cols);
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=this->data->get()[loc]-c;
            }
        }
        return *output;
}
Matrix_uchar& Matrix_uchar::operator-=(Matrix_uchar& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        uchar* dataA = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]-=dataA[loc];
            }
        }
        return *this;
}
Matrix& Matrix_uchar::operator-=(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相加矩阵形状不相同！");
        }
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(uchar)data2[loc];
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(uchar)data2[loc];
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(uchar)data2[loc];
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(uchar)data2[loc];
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(uchar)data2[loc];
                    }
                }
                break;
            }
            default:{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]-=(uchar)data2[loc];
                    }
                }
                break;
            }
        }
        return *this;
}
Matrix_uchar& Matrix_uchar::operator-=(uchar c){
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]-=c;
            }
        }
        return *this;
}
Matrix_uchar& Matrix_uchar::operator*(Matrix_uchar& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相乘矩阵形状不相同！");
        }
        Matrix_uchar * output = new Matrix_uchar(rows,cols);
        uchar* data1 = this->data->get();
        uchar* data2 = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=data1[loc]*data2[loc];
            }
        }
        return *output;
}
Matrix& Matrix_uchar::operator*(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相乘矩阵形状不相同！");
        }
        if(another.getMatrixType()>2){
            throw invalid_argument("error:uchar类型与浮点数的运算不兼容！");
        }
        Matrix_uchar * output = new Matrix_uchar(rows,cols);
        uchar* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(uchar)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(uchar)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(uchar)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
            default:{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(uchar)(data1[loc]*data2[loc]);
                    }
                }
                break;
            }
        }
        return *output;
}
Matrix_uchar& Matrix_uchar::operator*(uchar c){
        Matrix_uchar * output = new Matrix_uchar(rows,cols);
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=this->data->get()[loc]*c;
            }
        }
        return *output;
}
Matrix_uchar& Matrix_uchar::operator*=(Matrix_uchar& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相乘矩阵形状不相同！");
        }
        uchar* dataA = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]*=dataA[loc];
            }
        }
        return *this;
}
Matrix& Matrix_uchar::operator*=(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相乘矩阵形状不相同！");
        }
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(uchar)data2[loc];
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(uchar)data2[loc];
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(uchar)data2[loc];
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(uchar)data2[loc];
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(uchar)data2[loc];
                    }
                }
                break;
            }
            default:{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]*=(uchar)data2[loc];
                    }
                }
                break;
            }
        }
        return *this;
}
Matrix_uchar& Matrix_uchar::operator*=(uchar c){
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]*=c;
            }
        }
        return *this;
}
Matrix_uchar& Matrix_uchar::operator/(Matrix_uchar& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相除矩阵形状不相同！");
        }
        Matrix_uchar * output = new Matrix_uchar(rows,cols);
        uchar* data1 = this->data->get();
        uchar* data2 = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=data1[loc]/data2[loc];
            }
        }
        return *output;
}
Matrix& Matrix_uchar::operator/(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相除矩阵形状不相同！");
        }
        if(another.getMatrixType()>2){
            throw invalid_argument("error:uchar类型与浮点数的运算不兼容！");
        }
        Matrix_uchar * output = new Matrix_uchar(rows,cols);
        uchar* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(uchar)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(uchar)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(uchar)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
            default:{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        output->data->get()[loc]=(uchar)(data1[loc]/data2[loc]);
                    }
                }
                break;
            }
        }
        return *output;
}
Matrix_uchar& Matrix_uchar::operator/(uchar c){
        Matrix_uchar * output = new Matrix_uchar(rows,cols);
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                output->data->get()[loc]=this->data->get()[loc]/c;
            }
        }
        return *output;
}
Matrix_uchar& Matrix_uchar::operator/=(Matrix_uchar& another){
        if(this->cols!=another.cols || this->rows!=another.rows){
            throw invalid_argument("error:两个相除矩阵形状不相同！");
        }
        uchar* dataA = another.data->get();
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]/=dataA[loc];
            }
        }
        return *this;
}
Matrix& Matrix_uchar::operator/=(Matrix& another){
        if(this->cols!=another.getCols() || this->rows!=another.getRows()){
            throw invalid_argument("error:两个相除矩阵形状不相同！");
        }
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(uchar)data2[loc];
                    }
                }
                break;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(uchar)data2[loc];
                    }
                }
                break;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(uchar)data2[loc];
                    }
                }
                break;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(uchar)data2[loc];
                    }
                }
                break;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(uchar)data2[loc];
                    }
                }
                break;
            }
            default:{
                uchar* data2 = another.getUCharDataValue();
                for(size_t i=0;i<rows;i++){
                    for(size_t j=0;j<cols;j++){
                        size_t loc = i*cols+j;
                        this->data->get()[loc]/=(uchar)data2[loc];
                    }
                }
                break;
            }
        }
        return *this;
}
Matrix_uchar& Matrix_uchar::operator/=(uchar c){
        for(size_t i=0;i<rows;i++){
            for(size_t j=0;j<cols;j++){
                size_t loc = i*cols+j;
                this->data->get()[loc]/=c;
            }
        }
        return *this;
}

Matrix& Matrix_uchar::dot(Matrix& another){
        if(this->cols!=another.getRows()){
            throw invalid_argument("error：矩阵形状无法进行点乘");
        }
        uchar* data1 = this->data->get();
        switch (another.getMatrixType()){
            case(0):{
                uchar* data2 = another.getUCharDataValue();
                Matrix * output = new Matrix_int(this->rows,this->cols);
                int sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(int) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getIntDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            case(1):{
                short* data2 = another.getShortDataValue();
                Matrix *output = new Matrix_int(this->rows,this->cols);
                int sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(int) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getIntDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            case(2):{
                int* data2 = another.getIntDataValue();
                Matrix *output = new Matrix_int(this->rows,this->cols);
                int sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(int) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getIntDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            case(3):{
                float* data2 = another.getFloatDataValue();
                Matrix *output = new Matrix_double(this->rows,this->cols);
                double sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(double) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getDoubleDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            case(4):{
                double* data2 = another.getDoubleDataValue();
                Matrix *output = new Matrix_double(this->rows,this->cols);
                double sum=0.0;
                for(int i=0;i<this->rows * this->rows;i+=this->rows){
                    for(int j=0;j<another.getCols();j++){
                        sum=0;
                        for(int k=0;k<this->cols;k++){
                            sum +=(double) data1[i + k] * data2[k * another.getCols() + j];
                        }
                        output->getDoubleDataValue()[i + j] = sum;
                    }
                }
                return *output;
            }
            default:{
                return *this;
            }
        }
}
void Matrix_uchar::show(){
        uchar* raw = data->get();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout << raw[i*cols+j] << '\t';
            }
            cout << endl;
        }
        cout  << '(' << rows << " rows," << cols << " cols,unsigned char)" << endl;
}
uchar_ptr* Matrix_uchar::getData(){
            return this->data;
}
uchar* Matrix_uchar::getUCharDataValue(){
        return this->data->get();
}
void Matrix_uchar::zero(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                this->data->get()[i*cols+j] = 0;
            }
        }
}
void Matrix_uchar::clear(){
        delete this->data;
        this->rows = 0;
        this->cols = 0;
        this->MatrixType = -1;
}
