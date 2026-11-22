; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_52 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_38 () (_ BitVec 32))
(assert
 (let ((?x70955 (bvmul arg0_4 arg1_52)))
(let ((?x55237 (bvmul (_ bv4294967295 32) ?x70955)))
(let ((?x64051 (bvmul arg0_4 arg1_38)))
(let ((?x71136 (bvadd ?x64051 ?x55237)))
(and (distinct ?x71136 (_ bv0 32)) true))))))
(check-sat)
