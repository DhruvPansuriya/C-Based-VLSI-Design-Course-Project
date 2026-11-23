; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x75317 (bvmul arg0_1 arg1_1)))
(let ((?x64702 (bvmul (_ bv4294967295 32) ?x75317)))
(let ((?x33705 (bvmul arg0_1 arg1_8)))
(let ((?x65719 (bvadd ?x33705 ?x64702)))
(and (distinct ?x65719 (_ bv0 32)) true))))))
(check-sat)
