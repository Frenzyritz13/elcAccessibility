/************************************************************************************************
 * This code was automatically generated by Digital Twin Code Generator tool 0.6.3.
 * Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.
 *
 * Generated Date: Thursday, November 7, 2019
 ***********************************************************************************************/

#include "inc/utilities/urn_azureiot_devicemanagement_deviceinformation_interface.h"

#define MAX_MASSAGE_SIZE 256

//
// Application state associated with this interface.
// It contains the DIGITALTWIN_INTERFACE_CLIENT_HANDLE used for responses in callbacks along with properties set
// and representations of the property update and command callbacks invoked on given interface
//
typedef struct URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE_STATE_TAG
{
    DIGITALTWIN_INTERFACE_CLIENT_HANDLE interfaceClientHandle;

} URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE_STATE;

static URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE_STATE appState;

// Urn_azureiot_DeviceManagement_DeviceInformationInterface_PropertyCallback is invoked when a property is updated (or failed) going to server.
// ALL property callbacks will be routed to this function and just have the userContextCallback set to the propertyName.
// Product code will potentially have context stored in this userContextCallback.
static void Urn_azureiot_DeviceManagement_DeviceInformationInterface_PropertyCallback(DIGITALTWIN_CLIENT_RESULT digitalTwinReportedStatus, void* userContextCallback)
{
    if (digitalTwinReportedStatus == DIGITALTWIN_CLIENT_OK)
    {
        ReportProperty_Succeeded_Callback("Urn_azureiot_DeviceManagement_DeviceInformation", (const char*)userContextCallback);
        LogInfo("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: Updating property=<%s> succeeded", (const char*)userContextCallback);
    }
    else
    {
        ReportProperty_Error_Callback("Urn_azureiot_DeviceManagement_DeviceInformation", (const char*)userContextCallback);
        LogError("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: Updating property=<%s> failed, error=<%s>", (const char*)userContextCallback, MU_ENUM_TO_STRING(DIGITALTWIN_CLIENT_RESULT, digitalTwinReportedStatus));
    }
}

// Urn_azureiot_DeviceManagement_DeviceInformationInterface_ReportProperty_Internal is a helper function to report a Urn_azureiot_DeviceManagement_DeviceInformation's properties.
// It invokes underlying DigitalTwin API for reporting properties and sets up its callback on completion.
DIGITALTWIN_CLIENT_RESULT Urn_azureiot_DeviceManagement_DeviceInformationInterface_ReportProperty_Internal(DIGITALTWIN_INTERFACE_CLIENT_HANDLE interfaceHandle, const char* propertyName, const char* propertyData)
{
    DIGITALTWIN_CLIENT_RESULT result = DigitalTwin_InterfaceClient_ReportPropertyAsync(interfaceHandle, propertyName,
        (const char*)propertyData, NULL,
        Urn_azureiot_DeviceManagement_DeviceInformationInterface_PropertyCallback, (void*)propertyName);

    if (result == DIGITALTWIN_CLIENT_OK)
    {
        LogInfo("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: Queued async report read only property for %s", propertyName);
        
    }
    else
    {
        LogError("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: Reporting property=<%s> failed, error=<%s>", propertyName, MU_ENUM_TO_STRING(DIGITALTWIN_CLIENT_RESULT, result));
    }

    DigitalTwinClientHelper_Check();
    return result;
}

DIGITALTWIN_CLIENT_RESULT Urn_azureiot_DeviceManagement_DeviceInformationInterface_Property_ReportManufacturer()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: interfaceClientHandle is required to be initialized before reporting properties");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Urn_azureiot_DeviceManagement_DeviceInformation_SerializeManufacturerProperty(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return Urn_azureiot_DeviceManagement_DeviceInformationInterface_ReportProperty_Internal(appState.interfaceClientHandle, Urn_azureiot_DeviceManagement_DeviceInformationInterface_ManufacturerProperty, payloadBuffer);
    }
    else
    {
        LogError("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: serialize read only property manufacturer failed");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

DIGITALTWIN_CLIENT_RESULT Urn_azureiot_DeviceManagement_DeviceInformationInterface_Property_ReportModel()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: interfaceClientHandle is required to be initialized before reporting properties");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Urn_azureiot_DeviceManagement_DeviceInformation_SerializeModelProperty(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return Urn_azureiot_DeviceManagement_DeviceInformationInterface_ReportProperty_Internal(appState.interfaceClientHandle, Urn_azureiot_DeviceManagement_DeviceInformationInterface_ModelProperty, payloadBuffer);
    }
    else
    {
        LogError("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: serialize read only property model failed");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

DIGITALTWIN_CLIENT_RESULT Urn_azureiot_DeviceManagement_DeviceInformationInterface_Property_ReportSwVersion()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: interfaceClientHandle is required to be initialized before reporting properties");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Urn_azureiot_DeviceManagement_DeviceInformation_SerializeSwVersionProperty(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return Urn_azureiot_DeviceManagement_DeviceInformationInterface_ReportProperty_Internal(appState.interfaceClientHandle, Urn_azureiot_DeviceManagement_DeviceInformationInterface_SwVersionProperty, payloadBuffer);
    }
    else
    {
        LogError("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: serialize read only property swVersion failed");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

DIGITALTWIN_CLIENT_RESULT Urn_azureiot_DeviceManagement_DeviceInformationInterface_Property_ReportOsName()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: interfaceClientHandle is required to be initialized before reporting properties");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Urn_azureiot_DeviceManagement_DeviceInformation_SerializeOsNameProperty(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return Urn_azureiot_DeviceManagement_DeviceInformationInterface_ReportProperty_Internal(appState.interfaceClientHandle, Urn_azureiot_DeviceManagement_DeviceInformationInterface_OsNameProperty, payloadBuffer);
    }
    else
    {
        LogError("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: serialize read only property osName failed");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

DIGITALTWIN_CLIENT_RESULT Urn_azureiot_DeviceManagement_DeviceInformationInterface_Property_ReportProcessorArchitecture()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: interfaceClientHandle is required to be initialized before reporting properties");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Urn_azureiot_DeviceManagement_DeviceInformation_SerializeProcessorArchitectureProperty(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return Urn_azureiot_DeviceManagement_DeviceInformationInterface_ReportProperty_Internal(appState.interfaceClientHandle, Urn_azureiot_DeviceManagement_DeviceInformationInterface_ProcessorArchitectureProperty, payloadBuffer);
    }
    else
    {
        LogError("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: serialize read only property processorArchitecture failed");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

DIGITALTWIN_CLIENT_RESULT Urn_azureiot_DeviceManagement_DeviceInformationInterface_Property_ReportProcessorManufacturer()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: interfaceClientHandle is required to be initialized before reporting properties");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Urn_azureiot_DeviceManagement_DeviceInformation_SerializeProcessorManufacturerProperty(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return Urn_azureiot_DeviceManagement_DeviceInformationInterface_ReportProperty_Internal(appState.interfaceClientHandle, Urn_azureiot_DeviceManagement_DeviceInformationInterface_ProcessorManufacturerProperty, payloadBuffer);
    }
    else
    {
        LogError("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: serialize read only property processorManufacturer failed");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

DIGITALTWIN_CLIENT_RESULT Urn_azureiot_DeviceManagement_DeviceInformationInterface_Property_ReportTotalStorage()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: interfaceClientHandle is required to be initialized before reporting properties");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Urn_azureiot_DeviceManagement_DeviceInformation_SerializeTotalStorageProperty(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return Urn_azureiot_DeviceManagement_DeviceInformationInterface_ReportProperty_Internal(appState.interfaceClientHandle, Urn_azureiot_DeviceManagement_DeviceInformationInterface_TotalStorageProperty, payloadBuffer);
    }
    else
    {
        LogError("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: serialize read only property totalStorage failed");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

DIGITALTWIN_CLIENT_RESULT Urn_azureiot_DeviceManagement_DeviceInformationInterface_Property_ReportTotalMemory()
{
    if (appState.interfaceClientHandle == NULL)
    {
        LogError("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: interfaceClientHandle is required to be initialized before reporting properties");
    }

    char payloadBuffer[MAX_MASSAGE_SIZE];
    if (Urn_azureiot_DeviceManagement_DeviceInformation_SerializeTotalMemoryProperty(payloadBuffer, MAX_MASSAGE_SIZE))
    {
        return Urn_azureiot_DeviceManagement_DeviceInformationInterface_ReportProperty_Internal(appState.interfaceClientHandle, Urn_azureiot_DeviceManagement_DeviceInformationInterface_TotalMemoryProperty, payloadBuffer);
    }
    else
    {
        LogError("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: serialize read only property totalMemory failed");
        return DIGITALTWIN_CLIENT_ERROR;
    }
}

DIGITALTWIN_CLIENT_RESULT Urn_azureiot_DeviceManagement_DeviceInformationInterface_Property_ReportAll()
{
    DIGITALTWIN_CLIENT_RESULT result;

    // NOTE: Future versions of SDK will support ability to send multiple properties in a single
    // send.  For now, one at a time is sufficient albeit less efficient.
    if (((result = Urn_azureiot_DeviceManagement_DeviceInformationInterface_Property_ReportManufacturer()) != DIGITALTWIN_CLIENT_OK) ||
        ((result = Urn_azureiot_DeviceManagement_DeviceInformationInterface_Property_ReportModel()) != DIGITALTWIN_CLIENT_OK) ||
        ((result = Urn_azureiot_DeviceManagement_DeviceInformationInterface_Property_ReportSwVersion()) != DIGITALTWIN_CLIENT_OK) ||
        ((result = Urn_azureiot_DeviceManagement_DeviceInformationInterface_Property_ReportOsName()) != DIGITALTWIN_CLIENT_OK) ||
        ((result = Urn_azureiot_DeviceManagement_DeviceInformationInterface_Property_ReportProcessorArchitecture()) != DIGITALTWIN_CLIENT_OK) ||
        ((result = Urn_azureiot_DeviceManagement_DeviceInformationInterface_Property_ReportProcessorManufacturer()) != DIGITALTWIN_CLIENT_OK) ||
        ((result = Urn_azureiot_DeviceManagement_DeviceInformationInterface_Property_ReportTotalStorage()) != DIGITALTWIN_CLIENT_OK) ||
        ((result = Urn_azureiot_DeviceManagement_DeviceInformationInterface_Property_ReportTotalMemory()) != DIGITALTWIN_CLIENT_OK) )

    {
        LogError("DEVICE_INFO: Reporting properties failed.");
    }
    else
    {
        LogInfo("DEVICE_INFO: Queuing of all properties to be reported has succeeded");
    }

    return result;
}

// Urn_azureiot_DeviceManagement_DeviceInformationInterface_InterfaceRegisteredCallback is invoked when this interface
// is successfully or unsuccessfully registered with the service, and also when the interface is deleted.
static void Urn_azureiot_DeviceManagement_DeviceInformationInterface_InterfaceRegisteredCallback(DIGITALTWIN_CLIENT_RESULT dtInterfaceStatus, void* userInterfaceContext)
{
    LogInfo("Urn_azureiot_DeviceManagement_DeviceInformationInterface_InterfaceRegisteredCallback with status=<%s>, userContext=<%p>", MU_ENUM_TO_STRING(DIGITALTWIN_CLIENT_RESULT, dtInterfaceStatus), userInterfaceContext);
    if (dtInterfaceStatus == DIGITALTWIN_CLIENT_OK)
    {
        // Once the interface is registered, send our reported properties to the service.  
        // It *IS* safe to invoke most DigitalTwin API calls from a callback thread like this, though it 
        // is NOT safe to create/destroy/register interfaces now.
        LogInfo("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: Interface successfully registered.");
    }
    else if (dtInterfaceStatus == DIGITALTWIN_CLIENT_ERROR_INTERFACE_UNREGISTERING)
    {
        // Once an interface is marked as unregistered, it cannot be used for any DigitalTwin SDK calls.
        LogInfo("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: Interface received unregistering callback.");
    }
    else
    {
        LogError("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: Interface received failed, status=<%s>.", MU_ENUM_TO_STRING(DIGITALTWIN_CLIENT_RESULT, dtInterfaceStatus));
    }
}

//
// Create DigitalTwin interface client handle
//
DIGITALTWIN_INTERFACE_CLIENT_HANDLE Urn_azureiot_DeviceManagement_DeviceInformationInterface_Create()
{
    DIGITALTWIN_INTERFACE_CLIENT_HANDLE interfaceHandle;
    DIGITALTWIN_CLIENT_RESULT result;

    memset(&appState, 0, sizeof(URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE_STATE));

    if ((result = DigitalTwin_InterfaceClient_Create(Urn_azureiot_DeviceManagement_DeviceInformationInterfaceId,  Urn_azureiot_DeviceManagement_DeviceInformationInterfaceInstanceName, Urn_azureiot_DeviceManagement_DeviceInformationInterface_InterfaceRegisteredCallback, (void*)&appState, &interfaceHandle)) != DIGITALTWIN_CLIENT_OK)
    {
        LogError("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: Unable to allocate interface client handle for interfaceId=<%s>, interfaceInstanceName=<%s>, error=<%s>", Urn_azureiot_DeviceManagement_DeviceInformationInterfaceId, Urn_azureiot_DeviceManagement_DeviceInformationInterfaceInstanceName, MU_ENUM_TO_STRING(DIGITALTWIN_CLIENT_RESULT, result));
        interfaceHandle = NULL;
    }

    else
    {
        LogInfo("URN_AZUREIOT_DEVICEMANAGEMENT_DEVICEINFORMATION_INTERFACE: Created DIGITALTWIN_INTERFACE_CLIENT_HANDLE successfully for interfaceId=<%s>, interfaceInstanceName=<%s>, handle=<%p>", Urn_azureiot_DeviceManagement_DeviceInformationInterfaceId, Urn_azureiot_DeviceManagement_DeviceInformationInterfaceInstanceName, interfaceHandle);
        appState.interfaceClientHandle = interfaceHandle;
    }

    return interfaceHandle;
}

void Urn_azureiot_DeviceManagement_DeviceInformationInterface_Close(DIGITALTWIN_INTERFACE_CLIENT_HANDLE digitalTwinInterfaceClientHandle)
{
    // On shutdown, in general the first call made should be to DigitalTwin_InterfaceClient_Destroy.
    // This will block if there are any active callbacks in this interface, and then
    // mark the underlying handle such that no future callbacks shall come to it.
    DigitalTwin_InterfaceClient_Destroy(digitalTwinInterfaceClientHandle);

    // After DigitalTwin_InterfaceClient_Destroy returns, it is safe to assume
    // no more callbacks shall arrive for this interface and it is OK to free
    // resources callbacks otherwise may have needed.

}
