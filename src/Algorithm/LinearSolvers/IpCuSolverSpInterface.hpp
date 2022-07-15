// Copyright (C) 2022 COIN-OR Foundation
// This code is published under the Eclipse Public License.

#ifndef __IPCUSOLVERSPINTERFACE_HPP__
#define __IPCUSOLVERSPINTERFACE_HPP__

// CUDA includes
// todo

// Ipopt includes
#include "IpSparseSymLinearSolverInterface.hpp"

namespace Ipopt
{
    /** Interface to NVIDIA's cuSOLVER - A GPU accelerated library for decompositions
     * and linear system solutions for both dense and sparse matrices.
     * @remarks This linear solver requires the CUDA runtime, cuBLAS and cuLAPACK.
     * @see https://docs.nvidia.com/cuda/cusolver/index.html
     * @since 3.14.8
     */
    class IpCuSolverSpInterface final : public SparseSymLinearSolverInterface
    {
        public:
            /** @name Constructor/Destructor */
            ///@{
            /** Constructor */
            IpCuSolverSpInterface();

            /** Destructor */
            ~IpCuSolverSpInterface() override;
            ///@}

            bool InitializeImpl(
                const OptionsList& options,
                const std::string& prefix);

            /** @name Methods for requesting solution of the linear system. */
            ///@{
            virtual ESymSolverStatus InitializeStructure(
                Index        dim,
                Index        nonzeros,
                const Index* ia,
                const Index* ja);

            virtual Number* GetValuesArrayPtr();

            virtual ESymSolverStatus MultiSolve(
                bool         new_matrix,
                const Index* ia,
                const Index* ja,
                Index        nrhs,
                Number*      rhs_vals,
                bool         check_NegEVals,
                Index        numberOfNegEVals);

            virtual Index NumberOfNegEVals() const;
            ///@}

            //* @name Options of Linear solver */
            ///@{
            virtual bool IncreaseQuality();

            virtual bool ProvidesInertia() const;

            virtual EMatrixFormat MatrixFormat() const;
            ///@}

            ///@{
            static void RegisterOptions(SmartPtr<RegisteredOptions> roptions);
            ///@}

        private:
            std::vector<double> _values{};
            Index _numberOfNegativeEigenValues = 0;
    };
}

#endif // __IPCUSOLVERSPINTERFACE_HPP__
