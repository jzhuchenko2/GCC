//for some reason the gccc doesn't like the iostream being included here :(
#include <iostream>
//including the documentation of the xml library
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>

using namespace xercesc;

int main() {
    try {
        XMLPlatformUtils::Initialize();

        XercesDOMParser parser;
        parser.setValidationScheme(XercesDOMParser::Val_Never);
        parser.setDoNamespaces(false);
        parser.parse("catalog.xml");  //XML file

        DOMDocument* doc = parser.getDocument();
        DOMNodeList* books = doc->getElementsByTagName(XMLString::transcode("book"));

        for (XMLSize_t i = 0; i < books->getLength(); ++i) {
            DOMNode* bookNode = books->item(i);
            if (bookNode->getNodeType() && bookNode->getNodeType() == DOMNode::ELEMENT_NODE) {
                DOMElement* bookElement = dynamic_cast<DOMElement*>(bookNode);
                

                //g++ -o xml_reader gcc.cpp -lxerces-c

                
                DOMNodeList* titleList = bookElement->getElementsByTagName(XMLString::transcode("title"));
                if (titleList->getLength() > 0) {


                    
                    DOMNode* titleNode = titleList->item(0);
                    //run it from the cmd prompt 
                    //./xml_reader

                    std::cout << "Book Title: " << XMLString::transcode(titleNode->getTextContent()) << std::endl;
                }
            }
        }
        XMLPlatformUtils::Terminate();
    } catch (const XMLException& e) {
        //library must be installed 
        //this should read the XML file, extract book titles, and display them on the console.
        std::cerr << "error during bootstrapping " << XMLString::transcode(e.getMessage()) << std::endl;
        return 1;
    }
    return 0;
}

//<GCC_XML by CastXML
