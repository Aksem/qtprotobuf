/*
 * MIT License
 *
 * Copyright (c) 2019 Alexey Edelev <semlanik@gmail.com>, Tatyana Borisova <tanusshhka@mail.ru>
 *
 * This file is part of QtProtobuf project https://git.semlanik.org/semlanik/qtprotobuf
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify,
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and
 * to permit persons to whom the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "templates.h"

using namespace QtProtobuf::generator;

const char *Templates::ProtoSufix = "_proto";

const std::vector<std::string> Templates::ListOfQmlExeptions{"id", "property", "import"};

const char *Templates::DefaultProtobufIncludesTemplate = "#include <QMetaType>\n"
                                                         "#include <QList>\n"
                                                         "#include <QProtobufObject>\n"
                                                         "#include <QProtobufLazyMessagePointer>\n"
                                                         "#include <QSharedPointer>\n"
                                                         "\n"
                                                         "#include <memory>\n"
                                                         "#include <unordered_map>\n"
                                                         "\n";

const char *Templates::QmlProtobufIncludesTemplate = "#include <QtQml/QQmlListProperty>\n"
                                                     "#include <QQmlListPropertyConstructor>\n\n";

const char *Templates::GlobalEnumClassNameTemplate = "GlobalEnums";

const char *Templates::DisclaimerTemplate = "/* This file is autogenerated. DO NOT CHANGE. All changes will be lost */\n\n";

const char *Templates::PreambleTemplate = "#pragma once\n\n"
                                          "#include <QObject>\n";

const char *Templates::InternalIncludeTemplate =  "#include \"$include$.h\"\n";
const char *Templates::ExternalIncludeTemplate = "#include <$include$>\n";
const char *Templates::GlobalEnumIncludeTemplate = "#include <globalenums.h>\n";

const char *Templates::UsingQtProtobufNamespaceTemplate = "\nusing namespace QtProtobuf;\n";
const char *Templates::ManualRegistrationDeclaration = "static void registerTypes();\n";
const char *Templates::ManualRegistrationComplexTypeDefinition = "void $type$::registerTypes()\n{\n"
                                                                 "    qRegisterMetaType<$type$>(\"$full_type$\");\n"
                                                                 "    qRegisterMetaType<$type$*>(\"$full_type$*\");\n" //Somehow for aliastypes qRegisterMetaType logic doesn't work for pointer type registration
        "    qRegisterMetaType<$list_type$>(\"$full_list_type$\");\n"
        "";
const char *Templates::ManualRegistrationGlobalEnumDefinition = "void $enum_gadget$::registerTypes()\n{\n"
                                                                "";
const char *Templates::ComplexGlobalEnumFieldRegistrationTemplate = "qRegisterMetaType<$type$>(\"$full_type$\");\n";
const char *Templates::ComplexListTypeUsingTemplate = "using $classname$Repeated = QList<QSharedPointer<$classname$>>;\n";
const char *Templates::MapTypeUsingTemplate = "using $type$ = QMap<$key_type$, $value_type$>;\n";
const char *Templates::MessageMapTypeUsingTemplate = "using $type$ = QMap<$key_type$, QSharedPointer<$value_type$>>;\n";
const char *Templates::NestedMessageUsingTemplate = "using $type$ = $scope_namespaces$::$type$;\n"
                                                    "using $list_type$ = $scope_namespaces$::$list_type$;\n";

const char *Templates::EnumTypeRepeatedTemplate = "using $list_type$ = QList<$type$>;\n";

const char *Templates::NamespaceTemplate = "namespace $namespace$ {\n";
const char *Templates::UsingNamespaceTemplate = "using namespace $namespace$;\n";
const char *Templates::ClassDeclarationTemplate = "\nclass $classname$ : public QObject\n"
                                                  "{\n"
                                                  "    Q_OBJECT\n";
const char *Templates::ProtoClassForwardDeclarationTemplate = "class $classname$;\n";
const char *Templates::ProtoClassDeclarationBeginTemplate = "\nclass $classname$ : public QObject\n"
                                                            "{\n"
                                                            "    Q_OBJECT\n"
                                                            "    Q_PROTOBUF_OBJECT\n"
                                                            "    Q_DECLARE_PROTOBUF_SERIALIZERS($classname$)\n";

const char *Templates::PropertyTemplate = "Q_PROPERTY($property_type$ $property_name$ READ $property_name$ WRITE set$property_name_cap$ NOTIFY $property_name$Changed SCRIPTABLE $scriptable$)\n";
const char *Templates::RepeatedPropertyTemplate = "Q_PROPERTY($property_list_type$ $property_name$Data READ $property_name$ WRITE set$property_name_cap$ NOTIFY $property_name$Changed SCRIPTABLE $scriptable$)\n";
const char *Templates::NonScriptablePropertyTemplate = "Q_PROPERTY($property_type$ $property_name$_p READ $property_name$ WRITE set$property_name_cap$ NOTIFY $property_name$Changed SCRIPTABLE false)\n";
const char *Templates::NonScriptableAliasPropertyTemplate = "Q_PROPERTY($qml_alias_type$ $property_name$ READ $property_name$_p WRITE set$property_name_cap$_p NOTIFY $property_name$Changed SCRIPTABLE true)\n";
const char *Templates::MessagePropertyTemplate = "Q_PROPERTY($property_type$ *$property_name$ READ $property_name$_p WRITE set$property_name_cap$_p NOTIFY $property_name$Changed)\n";
const char *Templates::QmlListPropertyTemplate = "Q_PROPERTY(QQmlListProperty<$property_type$> $property_name$ READ $property_name$_l NOTIFY $property_name$Changed)\n";

const char *Templates::ConstructorParameterTemplate = "$scope_type$ $property_name$,";
const char *Templates::ConstructorMessageParameterTemplate = "const $scope_type$ &$property_name$,";
const char *Templates::ConstructorRepeatedParameterTemplate = "const $scope_list_type$ &$property_name$,";
const char *Templates::ProtoConstructorBeginTemplate = "$classname$(";
const char *Templates::ProtoConstructorEndTemplate = "QObject *parent = nullptr);\n";

const char *Templates::MemberTemplate = "$scope_type$ m_$property_name$;\n";
const char *Templates::ListMemberTemplate = "$scope_list_type$ m_$property_name$;\n";
const char *Templates::ComplexMemberTemplate = "QProtobufLazyMessagePointer<$scope_type$> m_$property_name$;\n";
const char *Templates::PublicBlockTemplate = "\npublic:\n";
const char *Templates::PrivateBlockTemplate = "\nprivate:\n";
const char *Templates::EnumDefinitionTemplate = "enum $type$ {\n";
const char *Templates::EnumFieldTemplate = "$enumvalue$ = $value$,\n";


const char *Templates::ProtoConstructorDefinitionBeginTemplate = "$type$::$type$(";
const char *Templates::ProtoConstructorDefinitionEndTemplate = "QObject *parent) : QObject(parent)";

const char *Templates::ConstructorTemplate = "$classname$();\n";
const char *Templates::QObjectConstructorTemplate = "explicit $classname$(QObject *parent = nullptr);\n";
const char *Templates::ConstructorHeaderTemplate = "$classname$() {}\n";
const char *Templates::CopyConstructorDeclarationTemplate = "$classname$(const $classname$ &other);\n";
const char *Templates::MoveConstructorDeclarationTemplate = "$classname$($classname$ &&other);\n";
const char *Templates::CopyConstructorDefinitionTemplate = "$classname$::$classname$(const $classname$ &other) : QObject()";
const char *Templates::MoveConstructorDefinitionTemplate = "$classname$::$classname$($classname$ &&other) : QObject()";
const char *Templates::EmptyCopyConstructorDefinitionTemplate = "$classname$::$classname$(const $classname$ &) : QObject()";
const char *Templates::EmptyMoveConstructorDefinitionTemplate = "$classname$::$classname$($classname$ &&) : QObject()";
const char *Templates::DeletedCopyConstructorTemplate = "$classname$(const $classname$ &) = delete;\n";
const char *Templates::DeletedMoveConstructorTemplate = "$classname$($classname$ &&) = delete;\n";
const char *Templates::CopyFieldTemplate = "set$property_name_cap$(other.m_$property_name$);\n";
const char *Templates::CopyComplexFieldTemplate = "if (m_$property_name$ != other.m_$property_name$) {\n"
                                                  "    *m_$property_name$ = *other.m_$property_name$;\n"
                                                  "}\n";
const char *Templates::AssignComplexFieldTemplate = "if (m_$property_name$ != other.m_$property_name$) {\n"
                                                    "    *m_$property_name$ = *other.m_$property_name$;\n"
                                                    "    $property_name$Changed();\n"
                                                    "}\n";
const char *Templates::MoveMessageFieldTemplate = "if (m_$property_name$ != other.m_$property_name$) {\n"
                                                  "    *m_$property_name$ = std::move(*other.m_$property_name$);\n"
                                                  "}\n";
const char *Templates::MoveAssignMessageFieldTemplate = "if (m_$property_name$ != other.m_$property_name$) {\n"
                                                        "    *m_$property_name$ = std::move(*other.m_$property_name$);\n"
                                                        "    $property_name$Changed();\n"
                                                        "    other.$property_name$Changed();\n"
                                                        "}\n";
const char *Templates::MoveComplexFieldTemplate = "if (m_$property_name$ != other.m_$property_name$) {\n"
                                                  "    m_$property_name$ = std::move(other.m_$property_name$);\n"
                                                  "    $property_name$Changed();\n"
                                                  "    other.$property_name$Changed();\n"
                                                  "}";

const char *Templates::MoveComplexFieldConstructorTemplate = "m_$property_name$ = std::move(other.m_$property_name$);\n"
                                                             "other.$property_name$Changed();\n";

const char *Templates::MoveFieldTemplate = "set$property_name_cap$(std::exchange(other.m_$property_name$, 0));\n"
                                           "other.$property_name$Changed();\n";
const char *Templates::EnumMoveFieldTemplate = "m_$property_name$ = other.m_$property_name$;\n";

const char *Templates::AssignmentOperatorDeclarationTemplate = "$classname$ &operator =(const $classname$ &other);\n";
const char *Templates::AssignmentOperatorDefinitionTemplate = "$classname$ &$classname$::operator =(const $classname$ &other)\n{\n";
const char *Templates::EmptyAssignmentOperatorDefinitionTemplate = "$classname$ &$classname$::operator =(const $classname$ &)\n{\n";
const char *Templates::AssignmentOperatorReturnTemplate = "return *this;\n";

const char *Templates::MoveAssignmentOperatorDeclarationTemplate = "$classname$ &operator =($classname$ &&other);\n";
const char *Templates::MoveAssignmentOperatorDefinitionTemplate = "$classname$ &$classname$::operator =($classname$ &&other)\n{\n";
const char *Templates::EmptyMoveAssignmentOperatorDefinitionTemplate = "$classname$ &$classname$::operator =($classname$ &&)\n{\n";

const char *Templates::EqualOperatorDeclarationTemplate = "bool operator ==(const $classname$ &other) const;\n";
const char *Templates::EqualOperatorDefinitionTemplate = "bool $classname$::operator ==(const $classname$ &other) const\n{\n"
                                                         "    return ";
const char *Templates::EmptyEqualOperatorDefinitionTemplate = "bool $classname$::operator ==(const $classname$ &) const\n{\n"
                                                              "    return true;\n"
                                                              "}\n\n";
const char *Templates::EqualOperatorPropertyTemplate = "m_$property_name$ == other.m_$property_name$";
const char *Templates::EqualOperatorMessagePropertyTemplate = "(m_$property_name$ == other.m_$property_name$\n"
                                                              "    || *m_$property_name$ == *other.m_$property_name$)\n";
const char *Templates::EqualOperatorRepeatedPropertyTemplate = "QtProtobuf::repeatedValueCompare(m_$property_name$, other.m_$property_name$)";

const char *Templates::NotEqualOperatorDeclarationTemplate = "bool operator !=(const $classname$ &other) const;\n";
const char *Templates::NotEqualOperatorDefinitionTemplate = "bool $classname$::operator !=(const $classname$ &other) const\n{\n"
                                                            "    return !this->operator ==(other);\n"
                                                            "}\n\n";

const char *Templates::GetterPrivateMessageDeclarationTemplate = "$getter_type$ *$property_name$_p() const;\n";
const char *Templates::GetterPrivateMessageDefinitionTemplate = "$getter_type$ *$classname$::$property_name$_p() const\n{\n"
                                                                "    return m_$property_name$.get();\n"
                                                                "}\n\n";

const char *Templates::GetterMessageDeclarationTemplate = "const $getter_type$ &$property_name$() const;\n";
const char *Templates::GetterMessageDefinitionTemplate = "const $getter_type$ &$classname$::$property_name$() const\n{\n"
                                                         "    return *m_$property_name$;\n"
                                                         "}\n\n";

const char *Templates::GetterTemplate = "$getter_type$ $property_name$() const {\n"
                                        "    return m_$property_name$;\n"
                                        "}\n\n";

const char *Templates::NonScriptableGetterTemplate = "$qml_alias_type$ $property_name$_p() const {\n"
                                                     "    return m_$property_name$;\n"
                                                     "}\n\n";

const char *Templates::GetterContainerExtraTemplate = "$getter_type$ &$property_name$() {\n"
                                                      "    return m_$property_name$;\n"
                                                      "}\n\n";

const char *Templates::GetterQmlListDeclarationTemplate = "QQmlListProperty<$scope_type$> $property_name$_l();\n";
const char *Templates::GetterQmlListDefinitionTemplate = "QQmlListProperty<$full_type$> $classname$::$property_name$_l()\n{\n"
                                                         "    return QtProtobuf::constructQmlListProperty<$scope_type$>(this, &m_$property_name$);\n"
                                                         "}\n\n";

const char *Templates::SetterPrivateTemplateDeclarationMessageType = "void set$property_name_cap$_p($setter_type$ *$property_name$);\n";
const char *Templates::SetterPrivateTemplateDefinitionMessageType = "void $classname$::set$property_name_cap$_p($setter_type$ *$property_name$)\n{\n"
                                                                    "    if (m_$property_name$.get() != $property_name$) {\n"
                                                                    "        m_$property_name$.reset($property_name$);\n"
                                                                    "        $property_name$Changed();\n"
                                                                    "    }\n"
                                                                    "}\n\n";

const char *Templates::SetterTemplateDeclarationMessageType = "void set$property_name_cap$(const $setter_type$ &$property_name$);\n";
const char *Templates::SetterTemplateDefinitionMessageType = "void $classname$::set$property_name_cap$(const $setter_type$ &$property_name$)\n{\n"
                                                             "    if (*m_$property_name$ != $property_name$) {\n"
                                                             "        *m_$property_name$ = $property_name$;\n"
                                                             "        $property_name$Changed();\n"
                                                             "    }\n"
                                                             "}\n\n";

const char *Templates::SetterTemplateDeclarationComplexType = "void set$property_name_cap$(const $setter_type$ &$property_name$);\n";
const char *Templates::SetterTemplateDefinitionComplexType = "void $classname$::set$property_name_cap$(const $setter_type$ &$property_name$)\n{\n"
                                                             "    if (m_$property_name$ != $property_name$) {\n"
                                                             "        m_$property_name$ = $property_name$;\n"
                                                             "        $property_name$Changed();\n"
                                                             "    }\n"
                                                             "}\n\n";

const char *Templates::SetterTemplate = "void set$property_name_cap$(const $setter_type$ &$property_name$) {\n"
                                        "    if (m_$property_name$ != $property_name$) {\n"
                                        "        m_$property_name$ = $property_name$;\n"
                                        "        $property_name$Changed();\n"
                                        "    }\n"
                                        "}\n\n";
const char *Templates::NonScriptableSetterTemplate = "void set$property_name_cap$_p(const $qml_alias_type$ &$property_name$) {\n"
                                                     "    if (m_$property_name$ != $property_name$) {\n"
                                                     "        m_$property_name$ = $property_name$;\n"
                                                     "        $property_name$Changed();\n"
                                                     "    }\n"
                                                     "}\n\n";

const char *Templates::SignalsBlockTemplate = "\nsignals:\n";
const char *Templates::SignalTemplate = "void $property_name$Changed();\n";

const char *Templates::FieldsOrderingContainerTemplate = "const QtProtobuf::QProtobufMetaObject $type$::protobufMetaObject = QtProtobuf::QProtobufMetaObject($type$::staticMetaObject, $type$::propertyOrdering);\n"
                                                         "const QtProtobuf::QProtobufPropertyOrdering $type$::propertyOrdering = {";
const char *Templates::FieldOrderTemplate = "{$field_number$, {$property_number$, \"$json_name$\"}}";

const char *Templates::EnumTemplate = "$type$";

const char *Templates::SimpleBlockEnclosureTemplate = "}\n";
const char *Templates::SemicolonBlockEnclosureTemplate = "};\n";
const char *Templates::EmptyBlockTemplate = "{}\n\n";
const char *Templates::PropertyInitializerTemplate = "\n    , m_$property_name$($property_name$)";
const char *Templates::PropertyDefaultInitializerTemplate = "\n    , m_$property_name$($initializer$)";
const char *Templates::MessagePropertyInitializerTemplate = "\n    , m_$property_name$(new $scope_type$($property_name$))";
const char *Templates::MessagePropertyDefaultInitializerTemplate = "\n    , m_$property_name$(nullptr)";
const char *Templates::ConstructorContentTemplate = "\n{\n}\n";

const char *Templates::DeclareMetaTypeTemplate = "Q_DECLARE_METATYPE($full_type$)\n";
const char *Templates::DeclareMetaTypeListTemplate = "Q_DECLARE_METATYPE($full_list_type$)\n";
const char *Templates::DeclareMessageMetaTypeTemplate = "Q_DECLARE_METATYPE($full_type$)\n"
                                                        "Q_DECLARE_OPAQUE_POINTER($full_type$)\n";

const char *Templates::DeclareComplexListTypeTemplate = "Q_DECLARE_METATYPE($full_list_type$)\n";
const char *Templates::DeclareComplexQmlListTypeTemplate = "Q_DECLARE_METATYPE(QQmlListProperty<$full_type$>)\n";

const char *Templates::DeclareMetaTypeMapTemplate = "#ifndef Q_PROTOBUF_MAP_$key_type_underscore$_$value_type_underscore$\n"
                                                    "#define Q_PROTOBUF_MAP_$key_type_underscore$_$value_type_underscore$\n"
                                                    "Q_DECLARE_METATYPE($full_type$)\n"
                                                    "#endif\n";


const char *Templates::RegisterLocalEnumTemplate = "qRegisterProtobufEnumType<$scope_type$>();\n"
                                                   "qRegisterMetaType<$scope_type$>(\"$type$\");\n"
                                                   "qRegisterMetaType<$scope_type$>(\"$full_type$\");\n"
                                                   "qRegisterMetaType<$scope_list_type$>(\"$full_list_type$\");\n";
const char *Templates::RegisterMapTemplate = "qRegisterMetaType<$scope_type$>(\"$full_type$\");\n"
                                             "qRegisterMetaType<$scope_type$>(\"$full_list_type$\");\n"
                                             "qRegisterProtobufMapType<$key_type$, $value_type$>();\n";

const char *Templates::RegisterMetaTypeTemplateNoNamespace = "qRegisterMetaType<$namespaces$::$type$>(\"$type$\");\n";
const char *Templates::RegisterMetaTypeTemplate = "qRegisterMetaType<$namespaces$::$type$>(\"$namespaces$::$type$\");\n";
const char *Templates::RegisterGlobalEnumMetaTypeTemplate = "qRegisterMetaType<$full_type$>(\"$full_type$\");\n";
const char *Templates::RegisterQmlListPropertyMetaTypeTemplate = "qRegisterMetaType<QQmlListProperty<$full_type$>>(\"QQmlListProperty<$full_type$>\");\n";


const char *Templates::QEnumTemplate = "Q_ENUM($type$)\n";

const char *Templates::ClassDefinitionTemplate = "\nclass $classname$ : public $parent_class$\n"
                                                 "{\n";
const char *Templates::QObjectMacro = "Q_OBJECT";
const char *Templates::ClientMethodDeclarationSyncTemplate = "QtProtobuf::QGrpcStatus $method_name$(const $param_type$ &$param_name$, const QPointer<$return_type$> &$return_name$);\n";
const char *Templates::ClientMethodDeclarationAsyncTemplate = "QtProtobuf::QGrpcCallReplyShared $method_name$(const $param_type$ &$param_name$);\n";
const char *Templates::ClientMethodDeclarationAsync2Template = "Q_INVOKABLE void $method_name$(const $param_type$ &$param_name$, const QObject *context, const std::function<void(QtProtobuf::QGrpcCallReplyShared)> &callback);\n";
const char *Templates::ClientMethodDeclarationQmlTemplate = "Q_INVOKABLE void $method_name$($param_type$ *$param_name$, const QJSValue &callback, const QJSValue &errorCallback);\n";
const char *Templates::ClientMethodDeclarationQml2Template = "Q_INVOKABLE void $method_name$($param_type$ *$param_name$, $return_type$ *$return_name$, const QJSValue &errorCallback);\n";

const char *Templates::ServerMethodDeclarationTemplate = "Q_INVOKABLE virtual $return_type$ $method_name$(const $param_type$ &$param_name$) = 0;\n";


const char *Templates::ClientConstructorDefinitionTemplate = "\n$classname$::$classname$(QObject *parent) : $parent_class$(\"$service_name$\", parent)\n"
                                                             "{\n"
                                                             "}\n";
const char *Templates::ClientMethodDefinitionSyncTemplate = "\nQtProtobuf::QGrpcStatus $classname$::$method_name$(const $param_type$ &$param_name$, const QPointer<$return_type$> &$return_name$)\n"
                                                            "{\n"
                                                            "    return call(\"$method_name$\", $param_name$, $return_name$);\n"
                                                            "}\n";
const char *Templates::ClientMethodDefinitionAsyncTemplate = "\nQtProtobuf::QGrpcCallReplyShared $classname$::$method_name$(const $param_type$ &$param_name$)\n"
                                                             "{\n"
                                                             "    return call(\"$method_name$\", $param_name$);\n"
                                                             "}\n";
const char *Templates::ClientMethodDefinitionAsync2Template = "\nvoid $classname$::$method_name$(const $param_type$ &$param_name$, const QObject *context, const std::function<void(QGrpcCallReplyShared)> &callback)\n"
                                                              "{\n"
                                                              "    QtProtobuf::QGrpcCallReplyShared reply = call(\"$method_name$\", $param_name$);\n"
                                                              "    QObject::connect(reply.get(), &QtProtobuf::QGrpcCallReply::finished, context, [reply, callback]() {\n"
                                                              "        callback(reply);\n"
                                                              "    });\n"
                                                              "}\n";

const char *Templates::ClientMethodDefinitionQmlTemplate = "\nvoid $classname$::$method_name$($param_type$ *$param_name$, const QJSValue &callback, const QJSValue &errorCallback)\n"
                                                           "{\n"
                                                           "    if (!callback.isCallable()) {\n"
                                                           "        qProtoWarning() << \"Unable to call $classname$::$method_name$, callback is not callable\";\n"
                                                           "        return;\n"
                                                           "    }\n\n"
                                                           "    if (arg == nullptr) {\n"
                                                           "        qProtoWarning() << \"Invalid argument provided for method $classname$::$method_name$, argument of type '$param_type$ *' expected\";\n"
                                                           "        return;\n"
                                                           "    }\n\n"
                                                           "    QJSEngine *jsEngine = qjsEngine(this);\n"
                                                           "    if (jsEngine == nullptr) {\n"
                                                           "        qProtoWarning() << \"Unable to call $classname$::$method_name$, it's only callable from JS engine context\";\n"
                                                           "        return;\n"
                                                           "    }\n\n"
                                                           "    QtProtobuf::QGrpcCallReplyShared reply = call(\"$method_name$\", *$param_name$);\n"
                                                           "    reply->subscribe(jsEngine, [this, reply, callback, jsEngine]() {\n"
                                                           "        auto result = new $return_type$(reply->read<$return_type$>());\n"
                                                           "        qmlEngine(this)->setObjectOwnership(result, QQmlEngine::JavaScriptOwnership);\n"
                                                           "        QJSValue(callback).call(QJSValueList{jsEngine->toScriptValue(result)});\n"
                                                           "    }, [errorCallback, jsEngine](const QGrpcStatus &status) {\n"
                                                           "        QJSValue(errorCallback).call(QJSValueList{jsEngine->toScriptValue(status)});\n"
                                                           "    });\n"
                                                           "}\n";
const char *Templates::ClientMethodDefinitionQml2Template = "\nvoid $classname$::$method_name$($param_type$ *$param_name$, $return_type$ *$return_name$, const QJSValue &errorCallback)\n"
                                                            "{\n"
                                                            "    if ($return_name$ == nullptr) {\n"
                                                            "        qProtoWarning() << \"Invalid argument provided for method $classname$::$method_name$, argument of type '$return_type$ *' expected\";\n"
                                                            "        return;\n"
                                                            "    }\n\n"
                                                            "    QPointer<$return_type$> safeReturn($return_name$);\n\n"
                                                            "    if ($param_name$ == nullptr) {\n"
                                                            "        qProtoWarning() << \"Invalid argument provided for method $classname$::$method_name$, argument of type '$param_type$ *' expected\";\n"
                                                            "        return;\n"
                                                            "    }\n\n"
                                                            "    QJSEngine *jsEngine = qjsEngine(this);\n"
                                                            "    if (jsEngine == nullptr) {\n"
                                                            "        qProtoWarning() << \"Unable to call $classname$::$method_name$, it's only callable from JS engine context\";\n"
                                                            "        return;\n"
                                                            "    }\n\n"
                                                            "    QtProtobuf::QGrpcCallReplyShared reply = call(\"$method_name$\", *$param_name$);\n"
                                                            "    reply->subscribe(jsEngine, [this, reply, jsEngine, safeReturn]() {\n"
                                                            "        if (safeReturn.isNull()) {\n"
                                                            "            qProtoWarning() << \"Return value is destroyed. Ignore call result\";\n"
                                                            "            return;\n"
                                                            "        }\n"
                                                            "        *safeReturn = $return_type$(reply->read<$return_type$>());\n"
                                                            "    }, [errorCallback, jsEngine](const QGrpcStatus &status) {\n"
                                                            "        QJSValue(errorCallback).call(QJSValueList{jsEngine->toScriptValue(status)});\n"
                                                            "    });\n"
                                                            "}\n";
const char *Templates::RegisterSerializersTemplate = "qRegisterProtobufType<$classname$>();\n";
const char *Templates::RegisterEnumSerializersTemplate = "qRegisterProtobufEnumType<$full_type$>();\n";
const char *Templates::RegistrarTemplate = "static QtProtobuf::ProtoTypeRegistrar<$classname$> ProtoTypeRegistrar$classname$(qRegisterProtobufType<$classname$>);\n";
const char *Templates::EnumRegistrarTemplate = "static QtProtobuf::ProtoTypeRegistrar<$enum_gadget$> ProtoTypeRegistrar$enum_gadget$($enum_gadget$::registerTypes);\n";
const char *Templates::QmlRegisterTypeTemplate = "qmlRegisterType<$scope_type$>(\"$qml_package$\", 1, 0, \"$type$\");\n";
const char *Templates::QmlRegisterEnumTypeTemplate = "qmlRegisterUncreatableType<$enum_gadget$>(\"$qml_package$\", 1, 0, \"$type$\", \"$full_type$ Could not be created from qml context\");\n";


const char *Templates::ClientMethodSignalDeclarationTemplate = "Q_SIGNAL void $method_name$Updated(const $return_type$ &);\n";
const char *Templates::ClientMethodServerStreamDeclarationTemplate = "QtProtobuf::QGrpcStreamShared stream$method_name_upper$(const $param_type$ &$param_name$);\n";
const char *Templates::ClientMethodServerStream2DeclarationTemplate = "QtProtobuf::QGrpcStreamShared stream$method_name_upper$(const $param_type$ &$param_name$, const QPointer<$return_type$> &$return_name$);\n";
const char *Templates::ClientMethodServerStreamQmlDeclarationTemplate = "Q_INVOKABLE QtProtobuf::QGrpcStreamShared qmlStream$method_name_upper$_p($param_type$ *$param_name$, $return_type$ *$return_name$);\n";

const char *Templates::ClientMethodServerStreamDefinitionTemplate = "QtProtobuf::QGrpcStreamShared $classname$::stream$method_name_upper$(const $param_type$ &$param_name$)\n"
                                                                    "{\n"
                                                                    "    return stream(\"$method_name$\", $param_name$);\n"
                                                                    "}\n";
const char *Templates::ClientMethodServerStream2DefinitionTemplate = "QtProtobuf::QGrpcStreamShared $classname$::stream$method_name_upper$(const $param_type$ &$param_name$, const QPointer<$return_type$> &$return_name$)\n"
                                                                     "{\n"
                                                                     "    return stream(\"$method_name$\", $param_name$, $return_name$);\n"
                                                                     "}\n";
const char *Templates::ClientMethodServerStreamQmlDefinitionTemplate = "QtProtobuf::QGrpcStreamShared $classname$::qmlStream$method_name_upper$_p($param_type$ *$param_name$, $return_type$ *$return_name$)\n"
                                                                       "{\n"
                                                                       "    return stream(\"$method_name$\", *$param_name$, QPointer<$return_type$>($return_name$));\n"
                                                                       "}\n";

const char *Templates::ListSuffix = "Repeated";


const std::unordered_map<::google::protobuf::FieldDescriptor::Type, std::string> Templates::TypeReflection = {
    {::google::protobuf::FieldDescriptor::TYPE_DOUBLE, "double"},
    {::google::protobuf::FieldDescriptor::TYPE_FLOAT, "float"},
    {::google::protobuf::FieldDescriptor::TYPE_INT64, "int64"},     //Limited usage see https://doc.qt.io/qt-5/qtqml-typesystem-basictypes.html
    {::google::protobuf::FieldDescriptor::TYPE_UINT64,"uint64"},    //Limited usage see https://doc.qt.io/qt-5/qtqml-typesystem-basictypes.html
    {::google::protobuf::FieldDescriptor::TYPE_INT32, "int32"},
    {::google::protobuf::FieldDescriptor::TYPE_FIXED64, "fixed64"},  //Limited usage see https://doc.qt.io/qt-5/qtqml-typesystem-basictypes.html
    {::google::protobuf::FieldDescriptor::TYPE_FIXED32, "fixed32"},
    {::google::protobuf::FieldDescriptor::TYPE_BOOL, "bool"},
    {::google::protobuf::FieldDescriptor::TYPE_STRING, "QString"},
    {::google::protobuf::FieldDescriptor::TYPE_BYTES, "QByteArray"},
    {::google::protobuf::FieldDescriptor::TYPE_UINT32, "uint32"},    //Limited usage see https://doc.qt.io/qt-5/qtqml-typesystem-basictypes.html
    {::google::protobuf::FieldDescriptor::TYPE_SFIXED32, "sfixed32"},
    {::google::protobuf::FieldDescriptor::TYPE_SFIXED64, "sfixed64"}, //Limited usage see https://doc.qt.io/qt-5/qtqml-typesystem-basictypes.html
    {::google::protobuf::FieldDescriptor::TYPE_SINT32, "sint32"},
    {::google::protobuf::FieldDescriptor::TYPE_SINT64, "sint64"}     //Limited usage see https://doc.qt.io/qt-5/qtqml-typesystem-basictypes.html
};

const char *Templates::ProtoFileSuffix = ".qpb";
const char *Templates::GrpcFileSuffix = "_grpc";

const char *Templates::EnumClassSuffix = "Gadget";

const char *Templates::QtProtobufNamespace = "QtProtobuf";
const char *Templates::QtProtobufNestedNamespace = "_QtProtobufNested";

const char *Templates::QtProtobufFieldEnum = "QtProtobufFieldEnum";
const char *Templates::FieldEnumTemplate = "enum QtProtobufFieldEnum {\n";
const char *Templates::FieldNumberTemplate = "$property_name_cap$ProtoFieldNumber = $number$,\n";
