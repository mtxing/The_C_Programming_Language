typedef long Align;

union header
{
    struct
    {
        union header *ptr;
        unsigned size;
    }s;
    Align x; /*进行强制对齐*/
};
typedef union header Header;