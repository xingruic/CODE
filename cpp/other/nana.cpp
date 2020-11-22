#include<nana>
int main()
{
    using namespace nana;

	form fm;

	textbox txbox(fm, rectangle{ 10, 50, 230, 100 });

	txbox.caption("abcdefg\n12345");

	place plc(fm);
	plc.div("|<>"); //plc.div("vert |<>"); //两种方式都未重现
	plc["a"] << txbox;
	plc.collocate();

	fm.show();

	exec();
}
