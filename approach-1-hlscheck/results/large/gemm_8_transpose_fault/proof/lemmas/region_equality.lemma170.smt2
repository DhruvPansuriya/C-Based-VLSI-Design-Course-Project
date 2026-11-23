; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_26 () (_ BitVec 32))
(declare-fun arg1_16 () (_ BitVec 32))
(assert
 (let ((?x63994 (bvmul arg0_26 arg1_2)))
(let ((?x61154 (bvmul (_ bv4294967295 32) ?x63994)))
(let ((?x64086 (bvmul arg0_26 arg1_16)))
(let ((?x57831 (bvadd ?x64086 ?x61154)))
(and (distinct ?x57831 (_ bv0 32)) true))))))
(check-sat)
