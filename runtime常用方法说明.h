
/// An opaque type that represents a method in a class definition.
//一个类的方法
typedef struct objc_method *Method;

/// An opaque type that represents an instance variable.
//实例变量
typedef struct objc_ivar *Ivar;

/// An opaque type that represents a category.
//分类
typedef struct objc_category *Category;

/// An opaque type that represents an Objective-C declared property.
//属性
typedef struct objc_property *objc_property_t;


struct objc_class {
    Class isa  OBJC_ISA_AVAILABILITY;
    
#if !__OBJC2__
    Class super_class    //父类                                     OBJC2_UNAVAILABLE;
    const char *name   //类名                                       OBJC2_UNAVAILABLE;
    long version     //版本                                         OBJC2_UNAVAILABLE;
    long info    //详细信息                                             OBJC2_UNAVAILABLE;
    long instance_size   //实例大小                                    OBJC2_UNAVAILABLE;
    struct objc_ivar_list *ivars    //实例变量列表                         OBJC2_UNAVAILABLE;
    struct objc_method_list **methodLists  //方法列表                  OBJC2_UNAVAILABLE;
    struct objc_cache *cache     //方法缓存                            OBJC2_UNAVAILABLE;
    struct objc_protocol_list *protocols   //协议列表                  OBJC2_UNAVAILABLE;
#endif
    
} OBJC2_UNAVAILABLE;
/* Use `Class` instead of `struct objc_class *` */

#endif

#ifdef __OBJC__
@class Protocol;
#else
typedef struct objc_object Protocol;
#endif

/// Defines a method
//方法描述
struct objc_method_description {
    SEL name;               /**< The name of the method */
    char *types;            /**< The types of the method arguments */
};

/// Defines a property attribute
//属性结构体
typedef struct {
    const char *name; //属性名          /**< The name of the attribute */
    const char *value; //属性值         /**< The value of the attribute (usually empty) */
} objc_property_attribute_t;




/**
 *  获取一个类
 *
 *  @param obj 对象名
 *
 *  @return 类
 */
OBJC_EXPORT Class object_getClass(id obj)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 *  根据一个对象设置一个类
 *
 *  @param obj 对象
 *  @param cls 类
 *
 *  @return 返回一个类
 */
OBJC_EXPORT Class object_setClass(id obj, Class cls)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);


/**
 *  判断对象是否是一个类
 *
 *  @param obj 对象
 *
 *  @return 是否是一个对象
 */
OBJC_EXPORT BOOL object_isClass(id obj)
__OSX_AVAILABLE_STARTING(__MAC_10_10, __IPHONE_8_0);


/**
 *  根据对象获取一个类名
 *
 *  @param obj 对象
 *
 *  @return 类名
 */
OBJC_EXPORT const char *object_getClassName(id obj)
__OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);


/**
 *  获取一个实例变量的值
 *
 *  @param obj  对象
 *  @param ivar 实例变量
 *
 */
OBJC_EXPORT id object_getIvar(id obj, Ivar ivar)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);


/**
 *  给一个对象的实例变量设置值
 *
 *  @param obj   对象
 *  @param ivar  实例变量
 *  @param value 值
 */

OBJC_EXPORT void object_setIvar(id obj, Ivar ivar, id value)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 * 修改对象实例变量
 *
 * @param obj 对象
 
 * @param name 属性名
 * @param value 值
 */
OBJC_EXPORT Ivar object_setInstanceVariable(id obj, const char *name, void *value)
__OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0)
OBJC_ARC_UNAVAILABLE;



/**
 * 获取对象实例变量
 *
 * @param obj 对象
 
 * @param name 属性名
 * @param value 值
 */
OBJC_EXPORT Ivar object_getInstanceVariable(id obj, const char *name, void **outValue);


/***  类相关函数 ***/
/**
 *    根据一个类名 获取一个类
 *
 *  @param name 名字
 *
 *  @return 类
 */
OBJC_EXPORT Class objc_getClass(const char *name)
__OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);


/**
 *  获取一个元类
 *
 *  @param name 类名
 *
 *  @return 元类
 */
OBJC_EXPORT Class objc_getMetaClass(const char *name)
__OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);



/**
 *  获取注册类的缓存数量
 *
 *  @param buffer      注册的数组
 *  @param bufferCount 数量
 *
 */
OBJC_EXPORT int objc_getClassList(Class *buffer, int bufferCount)
__OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);


/**
 *  拷贝已注册的类
 *
 *  @param outCount 数量
 *
 */
OBJC_EXPORT Class *objc_copyClassList(unsigned int *outCount)
__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_3_1);


/* 类相关函数 */

/**
 *  获取类名
 *
 *  @param cls 类
 *
 *  @return 类名
 */
OBJC_EXPORT const char *class_getName(Class cls)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 *  判断类是否是元类
 *
 *  @param cls 类
 *
 *  @return 是否是元类
 */
OBJC_EXPORT BOOL class_isMetaClass(Class cls)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);


/**
 *  获取当前类的父类
 *
 *  @param cls 当期类
 *
 *  @return 父类
 */
OBJC_EXPORT Class class_getSuperclass(Class cls)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 *  给当前类设置父类
 *
 *  @param cls      当前类
 *  @param newSuper 父类
 *
 *  @return 当前类
 */
OBJC_EXPORT Class class_setSuperclass(Class cls, Class newSuper)
__OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_5,__MAC_10_5, __IPHONE_2_0,__IPHONE_2_0);


/**
 *  获取类的大小
 *
 *  @param cls 当前类
 *
 *  @return 大小
 */

OBJC_EXPORT size_t class_getInstanceSize(Class cls);

/**
 *  获取当前实例的成员变量的值
 *
 * @param cls 当前类
 * @param name 成员变量名
 *
 * @return 成员变量
 */
OBJC_EXPORT Ivar class_getInstanceVariable(Class cls, const char *name);


/**
 *  获取当前类的成员变量的值
 *
 * @param cls 当前类
 * @param name 成员变量名
 *
 * @return 成员变量
 */
OBJC_EXPORT Ivar class_getClassVariable(Class cls, const char *name)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);




/**
 *  拷贝一个类的属性链表--数组
 *
 * @param cls 当前类
 * @param 数量
 *
 * @return 该类的所有属性
 */
OBJC_EXPORT Ivar *class_copyIvarList(Class cls, unsigned int *outCount)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);


/**
 *  获取实例的方法
 *
 *  @param cls  类
 *  @param name 方法名
 *
 *  @return Method 方法
 */
OBJC_EXPORT Method class_getInstanceMethod(Class cls, SEL name)
__OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);


/**
 *  获取类方法
 *
 *  @param cls  类
 *  @param name 方法名
 *
 *  @return 类方法
 */
OBJC_EXPORT Method class_getClassMethod(Class cls, SEL name)
__OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);


/**
 *  获取类方法实现
 *
 *  @param cls 当前类
 *  @param name 方法名
 *
 *  @return 方法的实现
 */
OBJC_EXPORT IMP class_getMethodImplementation(Class cls, SEL name)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 *  获取类方法实现
 *
 *  @param cls 当前类
 *  @param name 方法名
 *
 *  @return 方法的实现
 */
OBJC_EXPORT IMP class_getMethodImplementation_stret(Class cls, SEL name)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0)
OBJC_ARM64_UNAVAILABLE;


/**
 *  判断Selector是否响应
 *
 *  @param cls 类
 *  @param sel Selector
 *
 *  @return 是否响应
 */
OBJC_EXPORT BOOL class_respondsToSelector(Class cls, SEL sel)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);


/**
 *  获取一个类的方法列表
 *
 *  @param cls      类
 *  @param outCount 数量
 *
 *  @return 所有方法
 */
OBJC_EXPORT Method *class_copyMethodList(Class cls, unsigned int *outCount)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);


/**
 *  检查是否符合协议
 *
 *  @param cls      类
 *  @param protocol 协议
 *
 *  @return 是否符合与父类无关
 */
OBJC_EXPORT BOOL class_conformsToProtocol(Class cls, Protocol *protocol)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);


/**
 *  拷贝所有协议列表
 *
 *  @param cls      类
 *  @param outCount 数量
 *
 *  @return 协议列表
 */
OBJC_EXPORT Protocol * __unsafe_unretained *class_copyProtocolList(Class cls, unsigned int *outCount)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);


/**
 *  获取一个对象的属性
 *
 *  @param cls  类
 *  @param name 属性名
 *
 *  @return 属性
 */
OBJC_EXPORT objc_property_t class_getProperty(Class cls, const char *name)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);


/**
 *  拷贝属性列表
 *
 *  @param cls      类
 *  @param outCount 属性数量
 *
 *  @return 属性列表
 */
OBJC_EXPORT objc_property_t *class_copyPropertyList(Class cls, unsigned int *outCount)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);


/**
 *  动态的给类添加一个方法和实现
 *
 *  @param cls   类
 *  @param name  方法名
 *  @param imp   方法实现
 *  @param types 方法类型
 *
 *  @return 是否添加成功
 */
OBJC_EXPORT BOOL class_addMethod(Class cls, SEL name, IMP imp,
                                 const char *types)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);


/**
 *  动态的移除一个类的方法和实现
 *
 *  @param cls   类
 *  @param name  方法名
 *  @param imp   实现
 *  @param types 方法类型
 *
 *  @return 是否移除成功
 */
OBJC_EXPORT IMP class_replaceMethod(Class cls, SEL name, IMP imp,
                                    const char *types)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 * 添加一个新的实例变量
 *
 * @return 是否添加成功
 *
 * @note 添加的这个成员变量是不存在的
 * @note 这个类不能是元类，元类是不支持添加的
 */
OBJC_EXPORT BOOL class_addIvar(Class cls, const char *name, size_t size,
                               uint8_t alignment, const char *types)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 * 给类添加一个协议
 *
 * @param cls 当前类.
 * @param protocol 协议.
 *
 * @return 是否添加成功
 */
OBJC_EXPORT BOOL class_addProtocol(Class cls, Protocol *protocol)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 * 给类添加一个属性
 *
 * @param cls 这个类已经修改了.
 * @param name 属性名.
 * @param attributes  property数组.
 * @param attributeCount property数组长度.
 *
 * @return  是否添加成功
 */
OBJC_EXPORT BOOL class_addProperty(Class cls, const char *name, const objc_property_attribute_t *attributes, unsigned int attributeCount)
__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_4_3);

/**
 * 移除一个属性
 *
 * @param cls 这个类已经修改了
 * @param name 属性名
 * @param attributes  property 数组.
 * @param attributeCount property 数组长度
 */
OBJC_EXPORT void class_replaceProperty(Class cls, const char *name, const objc_property_attribute_t *attributes, unsigned int attributeCount)
__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_4_3);




/* 实例化一个类 相关 */


/**
 *  实例化一个类
 *
 *  @param cls        类
 *  @param extraBytes 大小
 *
 *  @return 实例化的类
 */
OBJC_EXPORT id class_createInstance(Class cls, size_t extraBytes)
__OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0)
OBJC_ARC_UNAVAILABLE;



/* 添加一个类 */

/**
 * 创建一个新的类或者是元类
 *
 * @param superclass 父类
 * @param name The  类名
 * @param extraBytes  类大小
 *
 * @return 创建好的类
 *
 */
OBJC_EXPORT Class objc_allocateClassPair(Class superclass, const char *name,
                                         size_t extraBytes)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 *  注册一个类
 *
 */
OBJC_EXPORT void objc_registerClassPair(Class cls)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);



/* 方法相关 */

/**
 *  获取一个方法
 *
 *  @param m 方法
 *
 *  @return 方法
 */
OBJC_EXPORT SEL method_getName(Method m)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);


/**
 *  获取一个方法实现
 *
 *  @param m 方法
 *
 *  @return 方法的实现
 */
OBJC_EXPORT IMP method_getImplementation(Method m)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 *  获取方法的类型编码
 *
 *  @param m 方法
 *
 *  @return 类型编码
 */
OBJC_EXPORT const char *method_getTypeEncoding(Method m)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 * 获取方法的参数数量
 *
 * @param m 方法
 *
 * @return 参数数量
 */
OBJC_EXPORT unsigned int method_getNumberOfArguments(Method m)
__OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/**
 * 拷贝方法的返回类型
 *
 * @param m 方法
 *
 * @return 返回类型
 */
OBJC_EXPORT char *method_copyReturnType(Method m)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);


/**
 *  根据索引拷贝参数类型
 *
 *  @param m     方法
 *  @param index 索引
 *
 *  @return 参数类型
 */
OBJC_EXPORT char *method_copyArgumentType(Method m, unsigned int index)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 *  获取方法的返回类型
 *
 * @param m 方法
 * @param dst 引用的字符串存储描述。
 * @param dst_len 大小
 *
 */
OBJC_EXPORT void method_getReturnType(Method m, char *dst, size_t dst_len)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 *  根据索引获取参数类型
 *
 *  @param m       方法
 *  @param index   索引
 *  @param dst_len 长度
 */
OBJC_EXPORT void method_getArgumentType(Method m, unsigned int index,
                                        char *dst, size_t dst_len)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);
OBJC_EXPORT struct objc_method_description *method_getDescription(Method m)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 *  设置方法的实现
 *
 *  @param m   方法
 *  @param imp 实现
 *
 */
OBJC_EXPORT IMP method_setImplementation(Method m, IMP imp)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 *  交换两个方法
 *
 *  @param m1 方法1
 *  @param m2 方法2
 */
OBJC_EXPORT void method_exchangeImplementations(Method m1, Method m2)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);


/* 实例变量相关 */

/**
 *  获取实例变量名
 *
 *  @param v 实力编码
 *
 *  @return 实例变量名
 */
OBJC_EXPORT const char *ivar_getName(Ivar v)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 * 获取实例变量编码
 *
 * @param v 实例变量
 *
 * @return A 类型编码
 *
 */
OBJC_EXPORT const char *ivar_getTypeEncoding(Ivar v)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 *  获取实例变量便宜地址
 *
 *  @param v 实例变量
 *
 *  @return 偏移地址
 */
OBJC_EXPORT ptrdiff_t ivar_getOffset(Ivar v)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);


/* 属性相关 */

/**
 *  获取属性名
 *
 *  @param property 属性
 *
 *  @return 属性名
 */
OBJC_EXPORT const char *property_getName(objc_property_t property)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 * 获取 property 的 attributes
 *
 * @param property A property.
 *
 */
OBJC_EXPORT const char *property_getAttributes(objc_property_t property)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 * 拷贝 property 的  attributes 列表
 *
 * @param outCount 数量
 *
 */
OBJC_EXPORT objc_property_attribute_t *property_copyAttributeList(objc_property_t property, unsigned int *outCount)
__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_4_3);

/**
 * 拷贝 property 的 attribute 列表的值
 *
 * @param property The property whose attribute value you are interested in.
 * @param attributeName attributeName名.
 *
 * @return The value string of the attribute \e attributeName if it exists in
 *  \e property, \c nil otherwise.
 */
OBJC_EXPORT char *property_copyAttributeValue(objc_property_t property, const char *attributeName)
__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_4_3);


/* 协议相关 */

/**
 * 根据名字获取协议
 *
 * @param name 协议名.
 *
 */
OBJC_EXPORT Protocol *objc_getProtocol(const char *name)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 * 拷贝协议列表
 *
 * @param outCount 遵守协议的数量
 *
 * @return A C array 协议列表
 */
OBJC_EXPORT Protocol * __unsafe_unretained *objc_copyProtocolList(unsigned int *outCount)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 * 检查A协议是否符合另一个协议
 *
 * @param proto A protocol.
 * @param other A protocol.
 *
 */
OBJC_EXPORT BOOL protocol_conformsToProtocol(Protocol *proto, Protocol *other)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 * 判断两个协议是否相等
 *
 * @param proto A protocol.
 * @param other A protocol.
 *
 * @return 是否相等
 */
OBJC_EXPORT BOOL protocol_isEqual(Protocol *proto, Protocol *other)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 * 获取协议名
 *
 * @param p A protocol.
 *
 * @return The name of the protocol \e p as a C string.
 */
OBJC_EXPORT const char *protocol_getName(Protocol *p)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 *  返回一个指定的方法的方法描述结构给定的协议。
 *
 * @param p A protocol.
 * @param aSel A selector.
 * @param isRequiredMethod A Boolean value that indicates whether aSel is a required method.
 * @param isInstanceMethod A Boolean value that indicates whether aSel is an instance method.
 *
 * @return An \c objc_method_description structure that describes the method specified by \e aSel,
 *  \e isRequiredMethod, and \e isInstanceMethod for the protocol \e p.
 *  If the protocol does not contain the specified method, returns an \c objc_method_description structure
 *  with the value \c {NULL, \c NULL}.
 *
 * @note This function recursively searches any protocols that this protocol conforms to.
 */
OBJC_EXPORT struct objc_method_description protocol_getMethodDescription(Protocol *p, SEL aSel, BOOL isRequiredMethod, BOOL isInstanceMethod)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 * Returns an array of method descriptions of methods meeting a given specification for a given protocol.
 *
 * @param p A protocol.
 * @param isRequiredMethod A Boolean value that indicates whether returned methods should
 *  be required methods (pass YES to specify required methods).
 * @param isInstanceMethod A Boolean value that indicates whether returned methods should
 *  be instance methods (pass YES to specify instance methods).
 * @param outCount Upon return, contains the number of method description structures in the returned array.
 *
 * @return A C array of \c objc_method_description structures containing the names and types of \e p's methods
 *  specified by \e isRequiredMethod and \e isInstanceMethod. The array contains \c *outCount pointers followed
 *  by a \c NULL terminator. You must free the list with \c free().
 *  If the protocol declares no methods that meet the specification, \c NULL is returned and \c *outCount is 0.
 *
 * @note Methods in other protocols adopted by this protocol are not included.
 */
OBJC_EXPORT struct objc_method_description *protocol_copyMethodDescriptionList(Protocol *p, BOOL isRequiredMethod, BOOL isInstanceMethod, unsigned int *outCount)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 * 获取协议属性
 *
 * @param proto A protocol.
 * @param name The name of a property.
 * @param isRequiredProperty A Boolean value that indicates whether name is a required property.
 * @param isInstanceProperty A Boolean value that indicates whether name is a required property.
 *
 * @return The property specified by \e name, \e isRequiredProperty, and \e isInstanceProperty for \e proto,
 *  or \c NULL if none of \e proto's properties meets the specification.
 */
OBJC_EXPORT objc_property_t protocol_getProperty(Protocol *proto, const char *name, BOOL isRequiredProperty, BOOL isInstanceProperty)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 * 拷贝协议的属性列表
 *
 * @param proto A protocol.
 * @param outCount Upon return, contains the number of elements in the returned array.
 *
 * @return A C array of pointers of type \c objc_property_t describing the properties declared by \e proto.
 *  Any properties declared by other protocols adopted by this protocol are not included. The array contains
 *  \c *outCount pointers followed by a \c NULL terminator. You must free the array with \c free().
 *  If the protocol declares no properties, \c NULL is returned and \c *outCount is \c 0.
 */
OBJC_EXPORT objc_property_t *protocol_copyPropertyList(Protocol *proto, unsigned int *outCount)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 * 拷贝协议列表(线程不安全)
 *
 * @param proto A protocol.
 * @param outCount Upon return, contains the number of elements in the returned array.
 *
 * @return A C array of protocols adopted by \e proto. The array contains \e *outCount pointers
 *  followed by a \c NULL terminator. You must free the array with \c free().
 *  If the protocol declares no properties, \c NULL is returned and \c *outCount is \c 0.
 */
OBJC_EXPORT Protocol * __unsafe_unretained *protocol_copyProtocolList(Protocol *proto, unsigned int *outCount)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 *  创建一个新的协议
 *
 *
 * @param name 协议名字.
 *
 */
OBJC_EXPORT Protocol *objc_allocateProtocol(const char *name)
__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_4_3);

/**
 * 注册协议
 *
 */
OBJC_EXPORT void objc_registerProtocol(Protocol *proto)
__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_4_3);

/**
 * 给协议添加一个方法
 *
 * @param proto The protocol to add a method to.
 * @param name The name of the method to add.
 * @param types A C string that represents the method signature.
 * @param isRequiredMethod YES if the method is not an optional method.
 * @param isInstanceMethod YES if the method is an instance method.
 */
OBJC_EXPORT void protocol_addMethodDescription(Protocol *proto, SEL name, const char *types, BOOL isRequiredMethod, BOOL isInstanceMethod)
__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_4_3);

/**
 * 添加一个协议
 *
 * @param proto The protocol you want to add to, it must be under construction.
 * @param addition The protocol you want to incorporate into \e proto, it must be registered.
 */
OBJC_EXPORT void protocol_addProtocol(Protocol *proto, Protocol *addition)
__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_4_3);

/**
 * 给协议添加一个属性
 *
 * @param proto The protocol to add a property to.
 * @param name The name of the property.
 * @param attributes An array of property attributes.
 * @param attributeCount The number of attributes in \e attributes.
 * @param isRequiredProperty YES if the property (accessor methods) is not optional.
 * @param isInstanceProperty YES if the property (accessor methods) are instance methods.
 *  This is the only case allowed fo a property, as a result, setting this to NO will
 *  not add the property to the protocol at all.
 */
OBJC_EXPORT void protocol_addProperty(Protocol *proto, const char *name, const objc_property_attribute_t *attributes, unsigned int attributeCount, BOOL isRequiredProperty, BOOL isInstanceProperty)
__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_4_3);


/* 镜像相关 */

/**
 *  拷贝镜像名
 *
 * @param outCount The number of names returned.
 *
 * @return An array of C strings of names. Must be free()'d by caller.
 */
OBJC_EXPORT const char **objc_copyImageNames(unsigned int *outCount)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 * 根据一个类获取镜像名
 *
 * @param cls 当前类
 *
 * @return 包含这个类库的名称
 */
OBJC_EXPORT const char *class_getImageName(Class cls)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 *  返回一个库中所有的类的名称列表。
 *
 * @param image 你询问的库或框架.
 * @param outCount 数量.
 *
 */
OBJC_EXPORT const char **objc_copyClassNamesForImage(const char *image,
                                                     unsigned int *outCount)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);


/* Selectors 相关 */

/**
 * 获取SEL的名称
 *
 * @param sel 选择器.
 *
 */
OBJC_EXPORT const char *sel_getName(SEL sel)
__OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/**
 * 获取一个Selectors的Uid
 *
 * @param str Selectors 名
 *
 */
OBJC_EXPORT SEL sel_getUid(const char *str)
__OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/**
 * 注册Selectors
 *
 *
 * @param str Selectors名
 *
 * @return A pointer of type SEL specifying the selector for the named method.
 *
 */
OBJC_EXPORT SEL sel_registerName(const char *str)
__OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/**
 *  判断Selectors是否相等
 *
 * @param lhs A Selectors .
 * @param rhs B Selectors
 *
 * @return 是否相等
 *
 */
OBJC_EXPORT BOOL sel_isEqual(SEL lhs, SEL rhs)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);


/* Objective-C Language 特征 */

/**
 * This function is inserted by the compiler when a mutation
 * is detected during a foreach iteration. It gets called
 * when a mutation occurs, and the enumerationMutationHandler
 * is enacted if it is set up. A fatal error occurs if a handler is not set up.
 *
 * @param obj The object being mutated.
 *
 */
OBJC_EXPORT void objc_enumerationMutation(id obj)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 * Sets the current mutation handler.
 *
 * @param handler Function pointer to the new mutation handler.
 */
OBJC_EXPORT void objc_setEnumerationMutationHandler(void (*handler)(id))
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 * Set the function to be called by objc_msgForward.
 *
 * @param fwd Function to be jumped to by objc_msgForward.
 * @param fwd_stret Function to be jumped to by objc_msgForward_stret.
 *
 * @see message.h::_objc_msgForward
 */
OBJC_EXPORT void objc_setForwardHandler(void *fwd, void *fwd_stret)
__OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

/**
 * Creates a pointer to a function that will call the block
 * when the method is called.
 *
 * @param block The block that implements this method. Its signature should
 *  be: method_return_type ^(id self, method_args...).
 *  The selector is not available as a parameter to this block.
 *  The block is copied with \c Block_copy().
 *
 * @return The IMP that calls this block. Must be disposed of with
 *  \c imp_removeBlock.
 */
OBJC_EXPORT IMP imp_implementationWithBlock(id block)
__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_4_3);

/**
 * Return the block associated with an IMP that was created using
 * \c imp_implementationWithBlock.
 *
 * @param anImp The IMP that calls this block.
 *
 * @return The block called by \e anImp.
 */
OBJC_EXPORT id imp_getBlock(IMP anImp)
__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_4_3);

/**
 * Disassociates a block from an IMP that was created using
 * \c imp_implementationWithBlock and releases the copy of the
 * block that was created.
 *
 * @param anImp An IMP that was created using \c imp_implementationWithBlock.
 *
 * @return YES if the block was released successfully, NO otherwise.
 *  (For example, the block might not have been used to create an IMP previously).
 */
OBJC_EXPORT BOOL imp_removeBlock(IMP anImp)
__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_4_3);

/**
 * This loads the object referenced by a weak pointer and returns it, after
 * retaining and autoreleasing the object to ensure that it stays alive
 * long enough for the caller to use it. This function would be used
 * anywhere a __weak variable is used in an expression.
 *
 * @param location The weak pointer address
 *
 * @return The object pointed to by \e location, or \c nil if \e location is \c nil.
 */
OBJC_EXPORT id objc_loadWeak(id *location)
__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_5_0);

/**
 * This function stores a new value into a __weak variable. It would
 * be used anywhere a __weak variable is the target of an assignment.
 *
 * @param location The address of the weak pointer itself
 * @param obj The new object this weak ptr should now point to
 *
 * @return The value stored into \e location, i.e. \e obj
 */
OBJC_EXPORT id objc_storeWeak(id *location, id obj)
__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_5_0);


/* Associative References */

/**
 * Policies related to associative references.
 * These are options to objc_setAssociatedObject()
 */
typedef OBJC_ENUM(uintptr_t, objc_AssociationPolicy) {
    OBJC_ASSOCIATION_ASSIGN = 0,           /**< Specifies a weak reference to the associated object. */
    OBJC_ASSOCIATION_RETAIN_NONATOMIC = 1, /**< Specifies a strong reference to the associated object.
                                            *   The association is not made atomically. */
    OBJC_ASSOCIATION_COPY_NONATOMIC = 3,   /**< Specifies that the associated object is copied.
                                            *   The association is not made atomically. */
    OBJC_ASSOCIATION_RETAIN = 01401,       /**< Specifies a strong reference to the associated object.
                                            *   The association is made atomically. */
    OBJC_ASSOCIATION_COPY = 01403          /**< Specifies that the associated object is copied.
                                            *   The association is made atomically. */
    };
    
    /**
     * 设置关联对象
     *
     * @param object 源对象
     * @param key The key for the association.
     * @param value The value to associate with the key key for object. Pass nil to clear an existing association.
     * @param policy The policy for the association. For possible values, see “Associative Object Behaviors.”
     *
     * @see objc_setAssociatedObject
     * @see objc_removeAssociatedObjects
     */
    OBJC_EXPORT void objc_setAssociatedObject(id object, const void *key, id value, objc_AssociationPolicy policy)
    __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_3_1);
    
    /**
     *  根据Key获取关联的对象
     *
     * @param object The source object for the association.
     * @param key The key for the association.
     *
     * @return The value associated with the key \e key for \e object.
     *
     * @see objc_setAssociatedObject
     */
    OBJC_EXPORT id objc_getAssociatedObject(id object, const void *key)
    __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_3_1);
    
    /**
     * 移除当前对象的所有关联
     *
     * @param object An object that maintains associated objects.
     *
     * @note The main purpose of this function is to make it easy to return an object
     *  to a "pristine state”. You should not use this function for general removal of
     *  associations from objects, since it also removes associations that other clients
     *  may have added to the object. Typically you should use \c objc_setAssociatedObject
     *  with a nil value to clear an association.
     *
     * @see objc_setAssociatedObject
     * @see objc_getAssociatedObject
     */
    OBJC_EXPORT void objc_removeAssociatedObjects(id object)
    __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_3_1);
    
    
#define _C_ID       '@'
#define _C_CLASS    '#'
#define _C_SEL      ':'
#define _C_CHR      'c'
#define _C_UCHR     'C'
#define _C_SHT      's'
#define _C_USHT     'S'
#define _C_INT      'i'
#define _C_UINT     'I'
#define _C_LNG      'l'
#define _C_ULNG     'L'
#define _C_LNG_LNG  'q'
#define _C_ULNG_LNG 'Q'
#define _C_FLT      'f'
#define _C_DBL      'd'
#define _C_BFLD     'b'
#define _C_BOOL     'B'
#define _C_VOID     'v'
#define _C_UNDEF    '?'
#define _C_PTR      '^'
#define _C_CHARPTR  '*'
#define _C_ATOM     '%'
#define _C_ARY_B    '['
#define _C_ARY_E    ']'
#define _C_UNION_B  '('
#define _C_UNION_E  ')'
#define _C_STRUCT_B '{'
#define _C_STRUCT_E '}'
#define _C_VECTOR   '!'
#define _C_CONST    'r'
    
    
    /* Obsolete types */
    
#if !__OBJC2__
    
#define CLS_GETINFO(cls,infomask)        ((cls)->info & (infomask))
#define CLS_SETINFO(cls,infomask)        ((cls)->info |= (infomask))
    
    // class is not a metaclass
#define CLS_CLASS               0x1
    // class is a metaclass
#define CLS_META                0x2
    // class's +initialize method has completed
#define CLS_INITIALIZED         0x4
    // class is posing
#define CLS_POSING              0x8
    // unused
#define CLS_MAPPED              0x10
    // class and subclasses need cache flush during image loading
#define CLS_FLUSH_CACHE         0x20
    // method cache should grow when full
#define CLS_GROW_CACHE          0x40
    // unused
#define CLS_NEED_BIND           0x80
    // methodLists is array of method lists
#define CLS_METHOD_ARRAY        0x100
    // the JavaBridge constructs classes with these markers
#define CLS_JAVA_HYBRID         0x200
#define CLS_JAVA_CLASS          0x400
    // thread-safe +initialize
#define CLS_INITIALIZING        0x800
    // bundle unloading
#define CLS_FROM_BUNDLE         0x1000
    // C++ ivar support
#define CLS_HAS_CXX_STRUCTORS   0x2000
    // Lazy method list arrays
#define CLS_NO_METHOD_ARRAY     0x4000
    // +load implementation
#define CLS_HAS_LOAD_METHOD     0x8000
    // objc_allocateClassPair API
#define CLS_CONSTRUCTING        0x10000
    // class compiled with bigger class structure
#define CLS_EXT                 0x20000
    
    
    struct objc_method_description_list {
        int count;
        struct objc_method_description list[1];
    };
    
    
    struct objc_protocol_list { //协议列表
        struct objc_protocol_list *next;//下一个协议
        long count;//数量
        Protocol *list[1];
    };
    
    
    struct objc_category {
        char *category_name     //分类名
        char *class_name        //类名
        struct objc_method_list *instance_methods          //实例方法列表      ;
        struct objc_method_list *class_methods             //类方法列表      ;
        struct objc_protocol_list *protocols               //协议列表           ;
    }                                                            ;
    
    
    struct objc_ivar {
        char *ivar_name   //成员变量名                                       OBJC2_UNAVAILABLE;
        char *ivar_type   //成员变量类型                                       OBJC2_UNAVAILABLE;
        int ivar_offset   //成员变量偏移地址                                       OBJC2_UNAVAILABLE;
#ifdef __LP64__
        int space                                                OBJC2_UNAVAILABLE;
#endif
    }                                                            OBJC2_UNAVAILABLE;
    
    struct objc_ivar_list {  //成员变量列表
        int ivar_count                  //成员变量数量                         OBJC2_UNAVAILABLE;
#ifdef __LP64__
        int space                                                OBJC2_UNAVAILABLE;
#endif
        /* variable length structure */
        struct objc_ivar ivar_list[1]                            OBJC2_UNAVAILABLE;
    }                                                            OBJC2_UNAVAILABLE;
    
    
    struct objc_method { //对象方法
        SEL method_name            //方法名                               OBJC2_UNAVAILABLE;
        char *method_types         //方法类型                              OBJC2_UNAVAILABLE;
        IMP method_imp             //方法实现                              OBJC2_UNAVAILABLE;
    }                                                            OBJC2_UNAVAILABLE;
    
    struct objc_method_list { //方法列表
        struct objc_method_list *obsolete                        OBJC2_UNAVAILABLE;
        
        int method_count               //方法数量                          OBJC2_UNAVAILABLE;
#ifdef __LP64__
        int space                                                OBJC2_UNAVAILABLE;
#endif
        /* variable length structure */
        struct objc_method method_list[1]                        OBJC2_UNAVAILABLE;
    }                                                            OBJC2_UNAVAILABLE;
    
    
    typedef struct objc_symtab *Symtab                           OBJC2_UNAVAILABLE;
    
    struct objc_symtab {
        unsigned long sel_ref_cnt                                OBJC2_UNAVAILABLE;
        SEL *refs                                                OBJC2_UNAVAILABLE;
        unsigned short cls_def_cnt                               OBJC2_UNAVAILABLE;
        unsigned short cat_def_cnt                               OBJC2_UNAVAILABLE;
        void *defs[1] /* variable size */                        OBJC2_UNAVAILABLE;
    }                                                            OBJC2_UNAVAILABLE;
    
    
    typedef struct objc_cache *Cache         //方法缓存                    OBJC2_UNAVAILABLE;
    
#define CACHE_BUCKET_NAME(B)  ((B)->method_name)
#define CACHE_BUCKET_IMP(B)   ((B)->method_imp)
#define CACHE_BUCKET_VALID(B) (B)
#ifndef __LP64__
#define CACHE_HASH(sel, mask) (((uintptr_t)(sel)>>2) & (mask))
#else
#define CACHE_HASH(sel, mask) (((unsigned int)((uintptr_t)(sel)>>3)) & (mask))
#endif
    struct objc_cache { // 方法缓存
        unsigned int mask /* total = mask + 1 */                 OBJC2_UNAVAILABLE;
        unsigned int occupied                                    OBJC2_UNAVAILABLE;
        Method buckets[1]                                        OBJC2_UNAVAILABLE;
    };
    
    
    typedef struct objc_module *Module                           OBJC2_UNAVAILABLE;
    
    struct objc_module {
        unsigned long version                                    OBJC2_UNAVAILABLE;
        unsigned long size                                       OBJC2_UNAVAILABLE;
        const char *name                                         OBJC2_UNAVAILABLE;
        Symtab symtab                                            OBJC2_UNAVAILABLE;
    }                                                            OBJC2_UNAVAILABLE;
    
#else
    
    struct objc_method_list;
    
#endif
    
    
#endif


