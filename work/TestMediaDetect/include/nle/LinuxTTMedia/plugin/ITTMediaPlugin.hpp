
#ifndef __def__media_plugin_export__header__
#define __def__media_plugin_export__header__

struct ITTMediaSourcePluginManager;
struct ITTMediaFileRenderManager;

enum
{
    MEDIA_PLUGIN_VTBL_Plugin,
};

struct MediaPluginVTBL
{
    enum 
    {
        id = MEDIA_PLUGIN_VTBL_Plugin
    };

    int (*funcInitMediaPlugin)();      /**< initMediaSource */
    int (*funcUninitMediaPlugin)();    /**< uninitMediaSource */

    int (*funcRegisteMediaSource)(ITTMediaSourcePluginManager*);      /**< registeMediaSourcePlugin */
    int (*funcUnregisteMediaSource)(ITTMediaSourcePluginManager*);    /**< unregisteMediaSourcePlugin */

    int (*funcRegisteMediaFileRender)(ITTMediaFileRenderManager*);      /**< registeMediaFileRenderPlugin */
    int (*funcUnregisteMediaFileRender)(ITTMediaFileRenderManager*);    /**< unregisteMediaFileRenderPlugin */

};

typedef void* (*funcPluginVTBL_t)(int id); /**< PluginVTBL */


#endif
