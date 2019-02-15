#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>

//functions
template <typename T>
std::string GetText(T pClass,std::string text) {
	std::string Str{ "<p class='" + pClass.name + "'>" + text + "</p>\n" };
	return Str;
}
std::string AddImage(std::string url, int sizeX, int sizeY, std::string imgFloat) {
	std::string imageStr = "<img src='" + url + "' style='width:" + std::to_string(sizeX) +
		"%;height: " + std::to_string(sizeY) + "%;float: " + imgFloat + "'>";

	return imageStr;
}
std::vector<std::string> GetTabs() {
	std::vector<std::string> tabVec;
	std::cout << "Add navigation bar tabs. Number of tabs: ";
	int n;
	std::cin >> n;
	tabVec.resize(n);
	for (int i = 0; i < tabVec.size();i++) {
		std::cout << "\nEnter tab: ";
		getline(std::cin, tabVec[i]);
	}
	return tabVec;
}
void WriteToFile(std::vector<std::string> vec, std::string name) {
	std::ofstream HtmlFile;
	HtmlFile.open(name + ".html", std::ios_base::out | std::ios_base::trunc);
	while (HtmlFile.is_open()) {
		HtmlFile << vec[0] << vec[1] << vec[2];
		HtmlFile.close();
	};

}

//classes
class NavBar {
public:
	std::vector<std::string> listItems, objPath;
	std::string navClass,backColor,hoverColor;
	int margin = 0,padding = 0;
	NavBar(std::vector<std::string> listItems, std::string color1, std::string color2) {
		this->listItems = listItems;
		backColor = color1;
		hoverColor = color2;
		for (int i = 0; i < size(listItems);i++) {
			objPath.push_back(listItems[i] + ".html");
		}
	}
	std::string getCss() {
		std::ostringstream navStream;
		std::string navBarString;
		navStream <<"ul.bar{\n"
			<< "list-style-type:none;\n"
			<< "margin:" << margin << ";\n"
			<< "padding:" << padding << "px;\n"
			<< "overflow:hidden;\n"
			<< "background-color:" << backColor << ";\n}\n";
		navStream << "li{\n"
			<< "float:left;\n}\n";
		navStream << "li a {\n"
			<< "display:block;\n color:white;\n text-align:center;\n padding: 16px;\n text-decoration:none;"
			<<"}\n";
		navStream << "li a:hover{\nbackground-color:" << hoverColor << ";\n}\n";

		navBarString = navStream.str();
		return navBarString;
	}
	std::string getHtml() {
		std::ostringstream navStream;
		std::string navBarString;
		//html
		navStream << "<ul class ='bar'> \n";
		for (int i = 0; i < size(listItems);i++) {
			navStream << "<li><a href = '" << objPath[i] << "'>" << listItems[i] << "</a></li>\n";
		}
		navStream << "</ul>\n";

		navBarString = navStream.str();
		return navBarString;
	}
};
class Table{
public:
	std::vector<std::string> tableStr = {"<table>","","</table>"};
	std::vector<std::string> cssStr = { "table,th,td{\n","","}\n" };
	Table(std::vector<std::string> vec) {
		tableStr[1] += "<tr>\n";
		for(int i = 0; i < vec.size();i++){
			tableStr[1] += "<th>" + vec[i] + "</th>\n";
		}
		tableStr[1] += "<tr>\n";
	}
	void addRow(std::vector<std::string> row) {
		tableStr.insert(tableStr.end() - 1, "<tr>\n");
		for (int i = 0; i < row.size();i++) {
			tableStr.insert( tableStr.end() - 1,"<td>" + row[i] + "</td>\n");
		}
		tableStr.insert(tableStr.end() - 1, "</tr>\n");
	}
	std::string getHtml() {
		std::string stringHTML = "";
		for (int i = 0; i < tableStr.size();i++) {
			stringHTML += tableStr[i];
		}
		return stringHTML;
	}
	std::string getCss(){
		return cssStr[0] + cssStr[1] + cssStr[2];

	}
};
class ParaClass {
public:
	std::string name;
	std::vector<std::string> cssStr{ "p.","","}\n" };
	ParaClass(std::string name, std::string font_color, std::string font_type, int size) {
		this->name = name;
		cssStr[0] += name + "{\n";
		cssStr[1] += "color: " + font_color + ";\nfont-family: " + font_type + 
			";\nfont-size: " + std::to_string(size) + "px;\n";
	}
	ParaClass(std::string name, std::string font_color, std::string font_type, int size, std::string border, 
		std::vector<int> padding) {
		this->name = name;
		cssStr[0] += name + "{\n";
		cssStr[1] += "color: " + font_color + ";\nfont-family: " + font_type +
			";\nfont-size: " + std::to_string(size) + "px;\nborder: " + border +
			";\npadding: ";
		for (int i = 0; i < padding.size();i++) {
			cssStr[1] += std::to_string(padding[i]) + "px ";
		}
		cssStr[1] += ";\n";
	}
	std::string GetCss() {
		return cssStr[0] + cssStr[1] + cssStr[2];
	}
};
class body {
public:
	std::string name, color, image, size = "100%", position = "", repeat = "";
	bool img;

	body(std::string name, std::string color) {
		this->name = name;
		this->color = color;
		img = false;
	}
	body(std::string name, std::string color, std::string image) {
		this->name = name;
		this->color = color;
		this->image = image;
		img = true;
	}
	std::string getCss() {
		std::ostringstream bodyStream;
		std::string bodyString;

		bodyStream << "body." << name << "{\n";
		bodyStream << "background-color:" << color << ";\n";
		if (img == true) {
			bodyStream << "background-image:url(" << '"' << image << '"' << ");\n";
		}
		bodyStream << "background-repeat:" << repeat << ";\n"
			<< "background-position:" << position << ";\n"
			<< "background-size:" << size << ";\n}\n";
		bodyString = bodyStream.str();
		return bodyString;
	}
	std::string getHtml() {
		std::string bodyString = "<body class='" + name + "'>\n";
		return bodyString;
	};
};

int main() {
	std::string fileName,title;
	std::cout << "Create new project name: ";
	getline(std::cin, fileName);
	
	body mainBody("home", "black", "back_home.png");
	NavBar barHome({ "Home","News","Account" }, "#202020", "#303030");
	Table table1({ "A","B","C" });
	table1.cssStr[1] += "color:white;\nbackground-color:black;\nborder:2px solid crimson;\nborder-collapse:collapse;\n";
	table1.addRow({ "Row 1.A","Row 1.B","Row 1.C" });
	table1.addRow({ "Row 2.A","Row 2.B","Row 2.C" });
	table1.cssStr[2] += "td:hover{\nbackground-color:#101010;\n}\n";
	ParaClass pHome("home", "black", "times-roman", 20);
	ParaClass pBlue("blue", "purple", "verdana", 16, "0px", {25,50,25,50});
	pBlue.cssStr[1] += "width: 25%;\n";
	pBlue.cssStr[1] += "background-color: powderblue;\n";
	std::vector<std::string> htmlVec = { "<html>\n<header>\n<link rel='stylesheet' href='" + fileName + ".css'>","","</body></header>\n</html>\n" };
	std::ofstream HtmlFile;
	std::ofstream CssFile;
	std::string txtToWrite;
	std::string txtFromFile;
	std::ifstream readFile;
	HtmlFile.open(fileName + ".html",std::ios_base::out | std::ios_base::trunc);
	CssFile.open(fileName + ".css", std::ios_base::out | std::ios_base::trunc);
	htmlVec[1] += mainBody.getHtml() + "<h1 style='color:white;background-color:#202020; width:40%'>WEB PAGE OPEN 4 BUSINESS</h1>" + barHome.getHtml() +
		AddImage("face.png", 25, 40, "right") + GetText(pHome,"Heyo! This must be working!\n") + GetText(pBlue,"I work too!\nTesting,testing 1,2,3....\nCan you still read me?\n")
		+  GetText(pBlue,"Here's some more text using one of our defined paragraph classes.\nJust keeps coming...") 
		+ table1.getHtml() + AddImage("kokoro.jpg", 60, 35, "none");									
	if (CssFile.is_open()) {
		CssFile << mainBody.getCss() << barHome.getCss() << pHome.GetCss() << pBlue.GetCss() << table1.getCss();
		CssFile.close();
	}
	if (HtmlFile.is_open()) {
		HtmlFile << htmlVec[0] << htmlVec[1] << htmlVec[2];
		HtmlFile.close();
	}


	return 0;
}