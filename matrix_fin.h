#include <iostream>
#include <memory>
using namespace std;

#ifndef uchar_def
#define uchar_def
typedef unsigned char uchar;
#endif


#ifndef packed_ptr_class
#define packed_ptr_class

class packed_ptr{}; // 基类 packed_ptr，用于包装下列指针于同一父类，在后续Matrix类中有作用
class uchar_ptr:public packed_ptr{
    uchar* data; // 指向对应类型数据的指针
    size_t* ref_time; // 跟踪引用次数的指针
    public:
    uchar* get();// 用于获取数据指针
    uchar_ptr(uchar* data);
    uchar_ptr(uchar_ptr & another);
    uchar_ptr & operator=(uchar_ptr & another);
    ~uchar_ptr();
};
//下列四类仅数据类型不同，结构相似
class short_ptr:public packed_ptr{
    short* data;
    size_t* ref_time;
    public:
    short* get();
    short_ptr(short* data);
    short_ptr(short_ptr & another);
    short_ptr & operator=(short_ptr & another);
    ~short_ptr();
};
class int_ptr:public packed_ptr{
    int* data;
    size_t* ref_time;
    public:
    int* get();
    int_ptr(int* data);
    int_ptr(int_ptr & another);
    int_ptr & operator=(int_ptr & another);
    ~int_ptr();
};
class float_ptr:public packed_ptr{
    float* data;
    size_t* ref_time;
    public:
    float* get();
    float_ptr(float* data);
    float_ptr(float_ptr & another);
    float_ptr & operator=(float_ptr & another);
    ~float_ptr();
};
class double_ptr:public packed_ptr{
    double* data;
    size_t* ref_time;
    public:
    double* get();
    double_ptr(double* data);
    double_ptr(double_ptr & another);
    double_ptr & operator=(double_ptr & another);
    ~double_ptr();
};

#endif


#ifndef Matrix_class
#define Matrix_class

class Matrix// Matrix 类，存储矩阵的基类
{
    protected:
        size_t rows = 0; // 矩阵行数
        size_t cols = 0; // 矩阵列数
        size_t MatrixType = -1; // 矩阵数据类型，不包含数据时，设为默认值-1
    public:
    Matrix(size_t rows,size_t cols);
    // 赋值运算符重载
    virtual Matrix & operator=(Matrix & another);
    // 相等/不等运算符重载
    virtual int operator==(Matrix& another);
    virtual int operator!=(Matrix& another);
    //加法运算重载
    virtual Matrix& operator+(Matrix& another);
    virtual Matrix& operator+(double c);
    virtual Matrix& operator+(float c);
    virtual Matrix& operator+(int c);
    virtual Matrix& operator+(short c);
    virtual Matrix& operator+(uchar c);
    virtual Matrix& operator+=(Matrix& another);
    template <typename T>
    Matrix& operator+=(T c);
    //减法运算重载
    virtual Matrix& operator-(Matrix& another);
    virtual Matrix& operator-(double c);
    virtual Matrix& operator-(float c);
    virtual Matrix& operator-(int c);
    virtual Matrix& operator-(short c);
    virtual Matrix& operator-(uchar c);
    virtual Matrix& operator-=(Matrix& another);
    template <typename T>
    Matrix& operator-=(T c);
    //乘法运算重载
    virtual Matrix& operator*(Matrix& another);
    virtual Matrix& operator*(double c);
    virtual Matrix& operator*(float c);
    virtual Matrix& operator*(int c);
    virtual Matrix& operator*(short c);
    virtual Matrix& operator*(uchar c);
    virtual Matrix& operator*=(Matrix& another);
    template <typename T>
    Matrix& operator*=(T c);
    //除法运算重载
    virtual Matrix& operator/(Matrix& another);
    virtual Matrix& operator/(double c);
    virtual Matrix& operator/(float c);
    virtual Matrix& operator/(int c);
    virtual Matrix& operator/(short c);
    virtual Matrix& operator/(uchar c);
    virtual Matrix& operator/=(Matrix& another);
    template <typename T>
    Matrix& operator/=(T c);

    friend std::ostream & operator<<(std::ostream & os, Matrix& m);//设定了<<的输出格式：逐行以制表符分割输出内容，并在末尾输出行列数

    friend std::istream & operator>>(std::istream & is, Matrix& m);//支持通过instream输入以单个任意分隔符，或任意长度的空格，换行符，制表符等分割的数字列，并将其排列为矩阵进行存储

    virtual Matrix& dot(Matrix& another);//矩阵点乘运算（支持混合类型）
    
    //对指定位置数据进行赋值或更改
    template <typename T>
    int edit(size_t i,size_t j,T datain);
    template <typename T>
    int add(size_t i,size_t j,T datain);
    template <typename T>
    int minus(size_t i,size_t j,T datain);
    template <typename T>
    int mul(size_t i,size_t j,T datain);
    template <typename T>
    int div(size_t i,size_t j,T datain);


    virtual void show();// 显示矩阵内容
    virtual packed_ptr* getData();// 在子类根据存储数据类型获取数据指针

    //用于在子类获取各类型的标准指针
    virtual uchar* getUCharDataValue();
    virtual short* getShortDataValue();
    virtual int* getIntDataValue();
    virtual float* getFloatDataValue();
    virtual double* getDoubleDataValue();

    // 获取、设置矩阵信息
    size_t getRows();
    size_t getCols();
    void setRows(size_t rows);
    void setCols(size_t rows);
    size_t getMatrixType();

    virtual void zero();// 将矩阵元素置零
    virtual void clear();// 清空矩阵数据
    
};

// Matrix_double 类，继承自 Matrix 类，用于存储double矩阵
class Matrix_double:public Matrix{
    private:
        double_ptr* data;//用于存储double矩阵的自定义指针
    public:
    Matrix_double(size_t rows,size_t cols);
    Matrix_double(size_t rows,size_t cols,double* data);
    ~Matrix_double();

    //赋值运算符重载
    Matrix& operator=(Matrix& another);
    Matrix_double& operator=(Matrix_double& another);
    // 相等/不等运算符重载
    int operator==(Matrix& another);
    int operator!=(Matrix& another);
    // 加法运算符重载
    Matrix_double& operator+(Matrix_double& another);
    Matrix& operator+(Matrix& another);
    Matrix_double& operator+(double c);
    Matrix_double& operator+=(Matrix_double& another);
    Matrix& operator+=(Matrix& another);
    Matrix_double& operator+=(double c);
    // 减法运算符重载
    Matrix_double& operator-(Matrix_double& another);
    Matrix& operator-(Matrix& another);
    Matrix_double& operator-(double c);
    Matrix_double& operator-=(Matrix_double& another);
    Matrix& operator-=(Matrix& another);
    Matrix_double& operator-=(double c);
    // 乘法运算符重载
    Matrix_double& operator*(Matrix_double& another);
    Matrix& operator*(Matrix& another);
    Matrix_double& operator*(double c);
    Matrix_double& operator*=(Matrix_double& another);
    Matrix& operator*=(Matrix& another);
    Matrix_double& operator*=(double c);
    // 除法运算符重载
    Matrix_double& operator/(Matrix_double& another);
    Matrix& operator/(Matrix& another);
    Matrix_double& operator/(double c);
    Matrix_double& operator/=(Matrix_double& another);
    Matrix& operator/=(Matrix& another);
    Matrix_double& operator/=(double c);


    Matrix& dot(Matrix& another);//矩阵点乘运算（支持混合类型）

    void show();// 显示矩阵内容

    double_ptr* getData();// 获取数据指针

    double* getDoubleDataValue();// 直接获取double标准数据指针(在使用父类指针时用于调用子类数据)

    void zero();// 将矩阵元素置零
    void clear();// 清空矩阵数据
};
//下列四类仅数据类型不同，结构相似

// Matrix_float 类，继承自 Matrix 类，用于存储float矩阵
class Matrix_float:public Matrix{
    private:
        float_ptr* data;
    public:
    Matrix_float(size_t rows,size_t cols);
    Matrix_float(size_t rows,size_t cols,float* data);
    ~Matrix_float();

    Matrix& operator=(Matrix& another);
    Matrix_float& operator=(Matrix_float& another);

    int operator==(Matrix& another);
    int operator!=(Matrix& another);

    Matrix_float& operator+(Matrix_float& another);
    Matrix& operator+(Matrix& another);
    Matrix_float& operator+(float c);
    Matrix_float& operator+(double c);
    Matrix_float& operator+=(Matrix_float& another);
    Matrix& operator+=(Matrix& another);
    Matrix_float& operator+=(float c);
    Matrix_float& operator+=(double c);

    Matrix_float& operator-(Matrix_float& another);
    Matrix& operator-(Matrix& another);
    Matrix_float& operator-(float c);
    Matrix_float& operator-=(Matrix_float& another);
    Matrix& operator-=(Matrix& another);
    Matrix_float& operator-=(float c);

    Matrix_float& operator*(Matrix_float& another);
    Matrix& operator*(Matrix& another);
    Matrix_float& operator*(float c);
    Matrix_float& operator*=(Matrix_float& another);
    Matrix& operator*=(Matrix& another);
    Matrix_float& operator*=(float c);

    Matrix_float& operator/(Matrix_float& another);
    Matrix& operator/(Matrix& another);
    Matrix_float& operator/(float c);
    Matrix_float& operator/=(Matrix_float& another);
    Matrix& operator/=(Matrix& another);
    Matrix_float& operator/=(float c);

    Matrix& dot(Matrix& another);

    void show();

    float_ptr* getData();

    float* getFloatDataValue();

    void zero();
    void clear();
};
// Matrix_int 类，继承自 Matrix 类，用于存储int矩阵
class Matrix_int:public Matrix{
    private:
        int_ptr* data;
    public:
    Matrix_int(size_t rows,size_t cols);
    Matrix_int(size_t rows,size_t cols,int* data);
    ~Matrix_int();

    Matrix& operator=(Matrix& another);
    Matrix_int& operator=(Matrix_int& another);

    int operator==(Matrix& another);
    int operator!=(Matrix& another);
    
    Matrix_int& operator+(Matrix_int& another);
    Matrix& operator+(Matrix& another);
    Matrix_int& operator+(int c);
    Matrix_int& operator+=(Matrix_int& another);
    Matrix& operator+=(Matrix& another);
    Matrix_int& operator+=(int c);

    Matrix_int& operator-(Matrix_int& another);
    Matrix& operator-(Matrix& another);
    Matrix_int& operator-(int c);
    Matrix_int& operator-=(Matrix_int& another);
    Matrix& operator-=(Matrix& another);
    Matrix_int& operator-=(int c);
    
    Matrix_int& operator*(Matrix_int& another);
    Matrix& operator*(Matrix& another);
    Matrix_int& operator*(int c);
    Matrix_int& operator*=(Matrix_int& another);
    Matrix& operator*=(Matrix& another);
    Matrix_int& operator*=(int c);

    Matrix_int& operator/(Matrix_int& another);
    Matrix& operator/(Matrix& another);
    Matrix_int& operator/(int c);
    Matrix_int& operator/=(Matrix_int& another);
    Matrix& operator/=(Matrix& another);
    Matrix_int& operator/=(int c);

    Matrix& dot(Matrix& another);

    void show();

    int_ptr* getData();

    int * getIntDataValue();

    void zero();
    void clear();
};
// Matrix_short 类，继承自 Matrix 类，用于存储short矩阵
class Matrix_short:public Matrix{
    private:
        short_ptr* data;
    public:
    Matrix_short(size_t rows,size_t cols);
    Matrix_short(size_t rows,size_t cols,short* data);
    ~Matrix_short();

    Matrix& operator=(Matrix& another);
    Matrix_short& operator=(Matrix_short& another);

    int operator==(Matrix& another);
    int operator!=(Matrix& another);

    Matrix_short& operator+(Matrix_short& another);
    Matrix& operator+(Matrix& another);
    Matrix_short& operator+(short c);
    Matrix_short& operator+=(Matrix_short& another);
    Matrix& operator+=(Matrix& another);
    Matrix_short& operator+=(short c);

    Matrix_short& operator-(Matrix_short& another);
    Matrix& operator-(Matrix& another);
    Matrix_short& operator-(short c);
    Matrix_short& operator-=(Matrix_short& another);
    Matrix& operator-=(Matrix& another);
    Matrix_short& operator-=(short c);

    Matrix_short& operator*(Matrix_short& another);
    Matrix& operator*(Matrix& another);
    Matrix_short& operator*(short c);
    Matrix_short& operator*=(Matrix_short& another);
    Matrix& operator*=(Matrix& another);
    Matrix_short& operator*=(short c);

    Matrix_short& operator/(Matrix_short& another);
    Matrix& operator/(Matrix& another);
    Matrix_short& operator/(short c);
    Matrix_short& operator/=(Matrix_short& another);
    Matrix& operator/=(Matrix& another);
    Matrix_short& operator/=(short c);

    Matrix& dot(Matrix& another);

    void show();

    short_ptr* getData();

    short* getShortDataValue();

    void zero();
    void clear();
};
// Matrix_uchar 类，继承自 Matrix 类，用于存储unsigned char矩阵
class Matrix_uchar:public Matrix{
    private:
        uchar_ptr* data;
    public:
    Matrix_uchar(size_t rows,size_t cols);
    Matrix_uchar(size_t rows,size_t cols,uchar* data);
    ~Matrix_uchar();

    Matrix& operator=(Matrix& another);
    Matrix_uchar& operator=(Matrix_uchar& another);

    int operator==(Matrix& another);
    int operator!=(Matrix& another);

    Matrix_uchar& operator+(Matrix_uchar& another);
    Matrix& operator+(Matrix& another);
    Matrix_uchar& operator+(uchar c);
    Matrix_uchar& operator+=(Matrix_uchar& another);
    Matrix& operator+=(Matrix& another);
    Matrix_uchar& operator+=(uchar c);

    Matrix_uchar& operator-(Matrix_uchar& another);
    Matrix& operator-(Matrix& another);
    Matrix_uchar& operator-(uchar c);
    Matrix_uchar& operator-=(Matrix_uchar& another);
    Matrix& operator-=(Matrix& another);
    Matrix_uchar& operator-=(uchar c);

    Matrix_uchar& operator*(Matrix_uchar& another);
    Matrix& operator*(Matrix& another);
    Matrix_uchar& operator*(uchar c);
    Matrix_uchar& operator*=(Matrix_uchar& another);
    Matrix& operator*=(Matrix& another);
    Matrix_uchar& operator*=(uchar c);

    Matrix_uchar& operator/(Matrix_uchar& another);
    Matrix& operator/(Matrix& another);
    Matrix_uchar& operator/(uchar c);
    Matrix_uchar& operator/=(Matrix_uchar& another);
    Matrix& operator/=(Matrix& another);
    Matrix_uchar& operator/=(uchar c);
    

    Matrix& dot(Matrix& another);

    void show();

    uchar_ptr* getData();

    uchar* getUCharDataValue();

    void zero();
    void clear();
};

#endif