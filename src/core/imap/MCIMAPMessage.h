#ifndef __MAILCORE_IMAP_MESSAGE_H_

#define __MAILCORE_IMAP_MESSAGE_H_

#include <MailCore/MCBaseTypes.h>
#include <MailCore/MCAbstractMessage.h>
#include <MailCore/MCMessageConstants.h>
#include <MailCore/MCAbstractPart.h>

#ifdef __cplusplus

namespace mailcore {
    
    class IMAPPart;
    class HTMLRendererIMAPCallback;
    class HTMLRendererTemplateCallback;
    
    class IMAPMessage : public AbstractMessage {
    public:
        IMAPMessage();
        virtual ~IMAPMessage();
        
        virtual uint32_t uid();
        virtual void setUid(uint32_t uid);
        
        virtual uint32_t size();
        virtual void setSize(uint32_t size);

        virtual void setFlags(MessageFlag flags);
        virtual MessageFlag flags();
        
        virtual void setOriginalFlags(MessageFlag flags);
        virtual MessageFlag originalFlags();
        
        virtual uint64_t modSeqValue();
        virtual void setModSeqValue(uint64_t uid);
        
        virtual void setMainPart(AbstractPart * mainPart);
        virtual AbstractPart * mainPart();
        
        virtual void setGmailLabels(Array * /* String */ labels);
        virtual Array * /* String */ gmailLabels();
        
        virtual void setGmailMessageID(uint64_t msgID);
        virtual uint64_t gmailMessageID();
        		
        virtual void setGmailThreadID(uint64_t threadID);
        virtual uint64_t gmailThreadID();
        
        virtual AbstractPart * partForPartID(String * partID);
        
        virtual AbstractPart * partForContentID(String * contentID);
        virtual AbstractPart * partForUniqueID(String * uniqueID);
        
        virtual String * htmlRendering(String * folder,
                                       HTMLRendererIMAPCallback * dataCallback,
                                       HTMLRendererTemplateCallback * htmlCallback = NULL);
        
    public: // subclass behavior
        IMAPMessage(IMAPMessage * other);
        virtual Object * copy();
        virtual String * description();
        virtual HashMap * serializable();
        virtual void importSerializable(HashMap * serializable);
        
    private:
        uint64_t mModSeqValue;
        uint32_t mUid;
        uint32_t mSize;

        MessageFlag mFlags;
        MessageFlag mOriginalFlags;
        AbstractPart * mMainPart;
        Array * /* String */ mGmailLabels;
        uint64_t mGmailMessageID;
        uint64_t mGmailThreadID;
        void init();
    };
    
}

#endif

#endif
