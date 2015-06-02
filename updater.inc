/**
 * Adds your plugin to the updater. The URL will be updated if 
 * your plugin was previously added.
 *
 * @param url      URL to your plugin's update file.
 * @noreturn
 */
native Updater_AddPlugin(const String:url[]);

/**
 * Removes your plugin from the updater. This does not need to 
 * be called during OnPluginEnd.
 *
 * @noreturn
 */
native Updater_RemovePlugin();

/**
 * Forces your plugin to be checked for updates. The behaviour 
 * of the update is dependant on the server's configuration.
 *
 * @return    True if an update was triggered. False otherwise.
 * @error      Plugin not found in updater.
 */
native bool:Updater_ForceUpdate();

/**
 * Called when your plugin is about to be checked for updates.
 *
 * @return    Plugin_Handled to prevent checking, Plugin_Continue to allow it.
 */
forward Action:Updater_OnPluginChecking();

/**
 * Called when your plugin is about to begin downloading an available update.
 *
 * @return    Plugin_Handled to prevent downloading, Plugin_Continue to allow it.
 */
forward Action:Updater_OnPluginDownloading();

/**
 * Called when your plugin's update files have been fully downloaded 
 * and are about to write to their proper location. This should be used 
 * to free read-only resources that require write access for your update.
 *
 * @note OnPluginUpdated will be called later during the same frame.
 *
 * @noreturn
 */
forward Updater_OnPluginUpdating();

/**
 * Called when your plugin's update has been completed. It is safe
 * to reload your plugin at this time.
 *
 * @noreturn
 */
forward Updater_OnPluginUpdated();