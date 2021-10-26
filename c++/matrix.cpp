template <typename T>
class Matrix {
    public:
        void resize(int rows, int cols);
        T& at(int row, int col);
        int rows() { return row; }
        int cols() { return col; }
    private:
        int row;
        int col;
        T **data;
};
