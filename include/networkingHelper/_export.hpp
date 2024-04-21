#if defined( NETWORKINGHELPER_DO_EXPORT_LINUX )

#define NETWORKINGHELPER_EXPORT __attribute__( ( dllexport ) ) __attribute__( ( visibility( "default" ) ) )

#elif defined( NETWORKINGHELPER_DO_EXPORT_MACOSX )

#define NETWORKINGHELPER_EXPORT __attribute__( ( visibility( "default" ) ) )

#elif defined( NETWORKINGHELPER_DO_EXPORT_WINDOWS )

#define NETWORKINGHELPER_EXPORT __declspec( dllexport )

#else

#define NETWORKINGHELPER_EXPORT

#endif
