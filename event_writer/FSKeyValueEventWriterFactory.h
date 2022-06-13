//
// Created by pablo on 16/05/2022.
//

#ifndef ChronoSQL_FSKEYVALUEEVENTWRITERFACTORY_H
#define ChronoSQL_FSKEYVALUEEVENTWRITERFACTORY_H


#include "EventWriterFactory.h"

#include <utility>
#include "FSKeyValueEventWriter.h"
#include "../Config/ConfigurationManager.h"

class FSKeyValueEventWriterFactory {
public:
    explicit FSKeyValueEventWriterFactory(const ConfigurationValues *configurationManager) :
            m_output_file(configurationManager->outputFile), payloadSize(configurationManager->payloadSize) {}

    [[nodiscard]] EventWriter *getWriter() const {
        return new FSKeyValueEventWriter(this->m_output_file, payloadSize);
    }

private:
    std::string m_output_file;
    int payloadSize;
};


#endif //ChronoSQL_FSKEYVALUEEVENTWRITERFACTORY_H
